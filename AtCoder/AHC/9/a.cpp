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
uniform_int_distribution<> rand4(0, 3) , rand1000(1,1000) ;

int sx , sy , gx , gy ;
int p ;
ld pp ;
char H[20][20] , V[20][20] ;

P prevv[20][20] ;
ll dp[20][20][20][20] ;
int dist[20][20][20][20] ;

void bfs(int sx , int sy , int gx , int gy){
    rep(i,20) rep(j,20) dist[sx][sy][i][j] = 1e8 ;
    dist[sx][sy][sx][sy] = 0 ;
    dp[sx][sy][sx][sy] = 1 ;
    queue<P> que ;
    que.push(P(sx,sy)) ;
    while(!que.empty()){
        P p = que.front() ;
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

int main(){
    cout << rand1000(mt) << endl ;
    int count = 0 ;
    cin >> sx >> sy >> gx >> gy >> pp ;
    p = (ld)pp * 1000 + 0.1 ;
    cout << p << endl ;

    rep(i,20) rep(j,19) cin >> H[i][j] ;
    rep(i,19) rep(j,20) cin >> V[i][j] ;
    int x = sx , y = sy ;
    int t = 0 ;
    string S = "" ;
    while(!(x == gx && y == gy)){
        int random_val = rand4(mt) ;
        if(rand1000(mt) <= p){
            if(random_val == 0){
                S += 'U' ;
                f(x,y,0) ;
            }
            if(random_val == 1){
                S += 'D' ;
                f(x,y,1) ;
            }
            if(random_val == 2){
                S += 'L' ;
                f(x,y,2) ;
            }
            if(random_val == 3){
                S += 'R' ;
                f(x,y,3) ;
            }
        }
        t++ ;
    }
    cout << S << endl ;
    cout << t << endl ;
}