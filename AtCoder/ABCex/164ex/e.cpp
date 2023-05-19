#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
    ll mon ;
};

int n , m , s ;
vector<edge> G[60] ;
ll dp[60][3030] ;
ll C[60] , D[60] ;

void djikstra(){
    rep(i,n) rep(j,3000) dp[i][j] = 1e16 ;
    dp[0][s] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,s}) ;
    while(!que.empty()){
        ll dist , v , val ;
        tie(dist,v,val) = que.top() ; que.pop() ;
        if(dp[v][val] < dist) continue ;
        if(dp[v][min(3000LL,val+C[v])] > dp[v][val] + D[v]){
            dp[v][min(3000LL,val+C[v])] = dp[v][val] + D[v] ;
            que.push({dp[v][min(3000LL,val+C[v])],v,min(3000LL,val+C[v])}) ;
        }
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            ll money = e.mon ;
            if(val >= money && dp[e.to][val - money] > dp[v][val] + e.cost){
                dp[e.to][val - money] = dp[v][val] + e.cost ;
                que.push({dp[e.to][val-money],e.to,val-money}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> s ;
    s = min(3000,s) ;
    rep(i,m){
        int u , v , a , b ;
        cin >> u >> v >> a >> b ;
        u-- ; v-- ;
        G[u].push_back(edge{v,b,a}) ;
        G[v].push_back(edge{u,b,a}) ;
    }
    rep(i,n) cin >> C[i] >> D[i] ;
    djikstra() ;
    rrep(i,1,n){
        ll res = 1e16 ;
        rep(j,3000){
            res = min(res,dp[i][j]) ;
        }
        cout << res << endl ;
    }
}