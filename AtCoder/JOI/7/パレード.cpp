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
    int to;
    ll cost;
};

ll n , m , L ;
vector<edge> G[1010] , F[1010] ;
ll d[1010][1010] ;

void djikstra(){
    rep(i,n) rep(j,m+1) d[i][j] = 1e16 ;
    d[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0}) ;
    while(!que.empty()){
        auto [dist,v,rev] = que.top() ; que.pop() ;
        if(dist > d[v][rev]) continue;
        for(edge e : G[v]){
            int u = e.to ;
            ll cost = e.cost ;
            if(d[u][rev] > d[v][rev] + cost){
                d[u][rev] = d[v][rev] + cost ;
                que.push({d[u][rev],u,rev}) ;
            }
        }
        if(rev == m) continue;
        for(edge e : F[v]){
            int u = e.to ;
            ll cost = e.cost ;
            if(d[u][rev+1] > d[v][rev] + cost){
                d[u][rev+1] = d[v][rev] + cost ;
                que.push({d[u][rev+1],u,rev+1}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> L ;
    rep(i,m){
        int v , u ;
        ll cost ;
        cin >> v >> u >> cost ;
        v-- ; u-- ;
        G[v].push_back(edge{u,cost}) ;
        F[u].push_back(edge{v,cost}) ;
    }
    djikstra() ;
    rep(i,m+1){
        if(d[n-1][i] <= L) {
            cout << i << endl ;
            return 0 ;
        }
    }
    cout << -1 << endl ;
}