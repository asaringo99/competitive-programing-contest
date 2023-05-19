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

struct edge{
    int to ;
    ll cost ;
} ;

int n , m ;
vector<edge> G[202020] ;
ll d[202020] ;

void bfs(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            int u = e.to ;
            if(d[u] > d[v] + e.cost){
                d[u] = d[v] + e.cost ;
                que.push(u) ;
            }
        }
    }
}


ll H[202020] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> H[i] ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        if(H[u] > H[v]){
            ll h = H[u] - H[v] ;
            G[u].push_back(edge{v,-h}) ;
            G[v].push_back(edge{u,2*h}) ;
        }
        else{
            ll h = H[v] - H[u] ;
            G[u].push_back(edge{v,2*h}) ;
            G[v].push_back(edge{u,-h}) ;
        }
    }
    bfs() ;
    ll res = 1e16 ;
    rep(i,n) chmin(res,d[i]) ;
    cout << -res << endl ;
}