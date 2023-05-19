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
};

int n , m ;

vector<edge> G[202020] ;
ll d[202020] ;

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
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int H[202020] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> H[i] ;
    rep(i,m){
        int v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        if(H[u] > H[v]){
            G[v].push_back(edge{u,H[u]-H[v]}) ;
            G[u].push_back(edge{v,0}) ;
        }
        else{
            G[v].push_back(edge{u,0}) ;
            G[u].push_back(edge{v,H[v]-H[u]}) ;
        }
    }
    djikstra() ;
    ll res = 1e18 ;
    rep(i,n) chmin(res,d[i]+H[i]-H[0]) ;
    cout << -res << endl ;
}