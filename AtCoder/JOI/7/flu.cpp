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

int n , m , dist , k ;
int C[2020][2020] ;
P X[101010] ;
vector<int> G[101010] ;

ll d[202020] ;
vector<ll> vec ;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> dist >> k ;
    rep(i,2010) rep(j,2010) C[i][j] = -1 ;
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        C[x][y] = i ;
        X[i] = P(x,y) ;
    }
    rep(i,n){
        auto[x,y] = X[i] ;
        rrep(dx,-dist,dist+1) rrep(dy,-dist,dist+1) {
            int nx = x + dx , ny = y + dy ;
            if(nx < 0 || ny < 0) continue;
            if(C[nx][ny] == -1) continue;
            if(C[nx][ny] == i) continue;
            if(dx * dx + dy * dy <= dist * dist) G[i].push_back(C[nx][ny]) ;
        }
    }
    djikstra() ;
    rep(i,n) vec.push_back(d[i]) ;
    sort(vec.begin(),vec.end()) ;
    int r = m - 1 ;
    int res = 0 ;
    int cnt = upper_bound(vec.begin(),vec.end(),k) - lower_bound(vec.begin(),vec.end(),k-r) ;
    cout << cnt << endl ;
}