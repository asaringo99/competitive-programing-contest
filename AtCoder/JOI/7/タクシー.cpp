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

int n , m ;
int C[5050] , R[5050] ;
vector<int> G[5050] ;
ll d[5050][5050] ;

void djikstra(){
    rep(i,n) rep(j,n+1) d[i][j] = 1e18 ;
    d[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0}) ;
    while(!que.empty()){
        auto[dist,v,r] = que.top() ; que.pop() ;
        if(dist > d[v][r]) continue;
        if(d[v][R[v]] > d[v][r] + C[v]){
            d[v][R[v]] = d[v][r] + C[v] ;
            que.push({d[v][R[v]],v,R[v]}) ;
        }
        if(r == 0) continue ;
        for(int u : G[v]){
            if(d[u][r-1] > d[v][r]){
                d[u][r-1] = d[v][r] ;
                que.push({d[u][r-1],u,r-1}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> C[i] >> R[i] ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    djikstra() ;
    ll res = 1e18 ;
    rep(i,n+1) chmin(res,d[n-1][i]) ;
    cout << res << endl ;
}