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

vector<vector<edge>> G , F;
ll d[202020][2] ;

void djikstra(int s , int type , vector<vector<edge>> G){
    rep(i,n) d[i][type] = 1e16 ;
    d[s][type] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        auto[dist,v] =  que.top() ; que.pop() ;
        if(d[v][type] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to][type] > d[v][type] + e.cost){
                d[e.to][type] = d[v][type] + e.cost ;
                que.push(P(d[e.to][type],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    G.resize(n) ;
    F.resize(n) ;
    rep(i,m){
        int u , v ;
        ll c ;
        cin >> u >> v >> c ;
        u-- ; v-- ;
        G[u].push_back(edge{v,c}) ;
        F[v].push_back(edge{u,c}) ;
    }
    djikstra(0,0,G) ;
    djikstra(n-1,1,F) ;
    rep(i,n){
        ll res = d[i][0] + d[i][1] ;
        cout << d[i][0] << " " << d[i][1] << endl ;
        if(res >= 1e15) res = -1 ;
        cout << res << endl;
    }
}