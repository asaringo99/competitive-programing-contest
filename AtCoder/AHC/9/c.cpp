#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

// 乱数発生器
random_device rnd ;
mt19937 mt(rnd()) ;
uniform_int_distribution<> rand100(1, 100) , rand1000(1,1000) ;

int sx , sy , gx , gy ;
int p ;
ld pp ;
char H[20][20] , V[20][20] ;

P node[20][20] ;
ll dp[20][20][20][20] ;
int dist[20][20][20][20] ;

void bfs(int sx , int sy){
    rep(i,20) rep(j,20) dist[sx][sy][i][j] = 1e8 ;
    dist[sx][sy][sx][sy] = 0 ;
    dp[sx][sy][sx][sy] = 1 ;
    queue<P> que ;
    que.push(P(sx,sy)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx < 0 || nx >= 20 || ny < 0 || ny >= 20) continue ;
            if(i == 0 && V[x][y]   == '1') continue ;
            if(i == 1 && V[x-1][y] == '1') continue ;
            if(i == 2 && H[x][y]   == '1') continue ;
            if(i == 3 && H[x][y-1] == '1') continue ;
            if(dist[sx][sy][nx][ny] == dist[sx][sy][x][y] + 1){
                dp[sx][sy][nx][ny] += dp[sx][sy][x][y] ;
            }
            if(dist[sx][sy][nx][ny] > dist[sx][sy][x][y] + 1){
                dp[sx][sy][nx][ny] = dp[sx][sy][x][y] ;
                dist[sx][sy][nx][ny] = dist[sx][sy][x][y] + 1 ;
                que.push(P(nx,ny)) ;
            }
        }
    }
}

void f(int& x , int& y , int ra){
    if(ra == 0) if(x - 1 >= 0 && V[x-1][y] == '0') x-- ;
    if(ra == 1) if(x + 1 < 20 && V[x][y]   == '0') x++ ;
    if(ra == 2) if(y - 1 >= 0 && H[x][y-1] == '0') y-- ;
    if(ra == 3) if(y + 1 < 20 && H[x][y]   == '0') y++ ;
}

bool g(int x , int y , int ra){
    if(ra == 0) if(x - 1 >= 0 && V[x-1][y] == '0') return true ;
    if(ra == 1) if(x + 1 < 20 && V[x][y]   == '0') return true ;
    if(ra == 2) if(y - 1 >= 0 && H[x][y-1] == '0') return true ;
    if(ra == 3) if(y + 1 < 20 && H[x][y]   == '0') return true ;
    return false ;
}

map<int,char> mp ;
map<char,int> cp ;

P h(string& S){
    rrep(i,S.size(),200){
        if(i % 4 == 0) S += 'U' ;
        if(i % 4 == 1) S += 'R' ;
        if(i % 4 == 2) S += 'D' ;
        if(i % 4 == 3) S += 'L' ;
    }
    int count = 0 ;
    int x = sx , y = sy ;
    rep(i,S.size()){
        int random_val = rand100(mt) ;
        if(random_val <= p) f(x,y,cp[S[i]]) ;
        if(x == gx && y == gy) return P(0,count) ;
        count++ ;
    }
    return P(dist[x][y][gx][gy],200) ;
}

string str(string S , ld tim1){
    set<int> st ;
    string res = "" ;
    int len = S.size() ;
    vector<bool> nonuse(S.size()) ;
    uniform_int_distribution<> rander(0, S.size()-1) ;
    while((clock() - tim1) / CLOCKS_PER_SEC < 1.95 && len - st.size() > 200){
        int ava = rander(mt) ;
        st.insert(ava) ;
        nonuse[ava] = true ;
    }
    rep(i,S.size()){
        if(nonuse[i]) continue ;
        res += S[i] ;
    }
    return res ;
}


int main(){
    ld tim1 = clock() ;
    mp[0] = 'U' ;
    mp[1] = 'D' ;
    mp[2] = 'L' ;
    mp[3] = 'R' ;
    cp['U'] = 0 ;
    cp['D'] = 1 ;
    cp['L'] = 2 ;
    cp['R'] = 3 ;
    int p40 = 70 ;
    int p41 = 90 ;
    int p42 = 95 ;
    int p30 = 70 ;
    int p31 = 90 ;
    int p20 = 90 ;
    cin >> sx >> sy >> gx >> gy >> pp ;
    p = (ld)pp * 1000 + 0.1 ;
    rep(i,20) rep(j,19) cin >> H[i][j] ;
    rep(i,19) rep(j,20) cin >> V[i][j] ;
    rep(i,20) rep(j,20) bfs(i,j) ;
    rep(i,20) rep(j,20) node[i][j] = P(dist[i][j][gx][gy],-dp[i][j][gx][gy]) ;
    using PP = pair<P,int> ;
    P score = P(1e18,1e18) ;
    string res = "RDRURLRULRLRLURULURURURURUDDRURURULRURULRURLRURURLRDRDRLDURDRDLLDRDRDLDRDRDUDUDUDUDUDUDUDRUDRDUDDRDRDRDRURDRLDRDDRDRDRDUDRUDUDRDLLDRDRDURDRUDUDRDRDRUDRLULUDLLUDDRUURLRULRDRDRDURUDUDRDRDRDRDRDLDRDRDRDR" ;

    while((clock() - tim1) / CLOCKS_PER_SEC < 1.95){
        int x = sx , y = sy ;
        int t = 0 ;
        string S = "" ;
        int prevv = -1 ;
        while((clock() - tim1) / CLOCKS_PER_SEC < 1.95 && !(x == gx && y == gy)){
            int ppp = rand1000(mt) ;
            int random_val = rand100(mt) ;
            vector<PP> vec ;
            if(g(x,y,0) && prevv != 0) vec.push_back(PP(node[x-1][y],0)) ;
            if(g(x,y,1) && prevv != 1) vec.push_back(PP(node[x+1][y],1)) ;
            if(g(x,y,2) && prevv != 2) vec.push_back(PP(node[x][y-1],2)) ;
            if(g(x,y,3) && prevv != 3) vec.push_back(PP(node[x][y+1],3)) ;
            sort(vec.begin(),vec.end()) ;
            vector<int> order ;
            for(PP p : vec) order.push_back(p.second) ;
            if(0 <= prevv && prevv <= 3) order.push_back(prevv) ;
            if(order.size() == 4){
                if(random_val <= p40){
                    S += mp[order[0]] ;
                    if(ppp >= p) f(x,y,order[0]) ;
                    prevv = order[0] ;
                }
                else if(random_val <= p41){
                    S += mp[order[1]] ;
                    if(ppp <= p) f(x,y,order[1]) ;
                    prevv = order[1] ;
                }
                else if(random_val <= p42){
                    S += mp[order[2]] ;
                    if(ppp <= p) f(x,y,order[2]) ;
                    prevv = order[2] ;
                }
                else{
                    S += mp[order[3]] ;
                    if(ppp <= p) f(x,y,order[3]) ;
                    prevv = order[3] ;
                }
            }
            else if(order.size() == 3){
                if(random_val <= p30){
                    S += mp[order[0]] ;
                    if(ppp <= p) f(x,y,order[0]) ;
                    prevv = order[0] ;
                }
                else if(random_val <= p31){
                    S += mp[order[1]] ;
                    if(ppp <= p) f(x,y,order[1]) ;
                    prevv = order[1] ;
                }
                else{
                    S += mp[order[2]] ;
                    if(ppp <= p) f(x,y,order[2]) ;
                    prevv = order[2] ;
                }
            }
            else if(order.size() == 2){
                if(random_val <= p20){
                    S += mp[order[0]] ;
                    if(ppp <= p) f(x,y,order[0]) ;
                    prevv = order[0] ;
                }
                else{
                    S += mp[order[1]] ;
                    if(ppp <= p) f(x,y,order[1]) ;
                    prevv = order[1] ;
                }
            }
            else{
                S += mp[order[0]] ;
                if(ppp <= p) f(x,y,order[0]) ;
                prevv = order[0] ;
            }
            t++ ;
        }
        if(t > 200) S = str(S,tim1) ;
        
        P ss = P(0,0) ;
        rep(i,100){
            P value = h(S) ;
            ss = P(ss.first+value.first,ss.second+value.second) ;
        }
        if(ss < score){
            score = ss ;
            res = S ;
        }
    }
    cout << res << endl ;
}