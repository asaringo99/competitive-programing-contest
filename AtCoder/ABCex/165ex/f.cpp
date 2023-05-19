#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<int> vec ;
vector<int> G[202020] ;
ll A[202020] ;
ll dp[202020] ;
ll res[202020] ;

void dfs(int v , int prev){
    auto it = lower_bound(dp,dp+n,A[v]) ;
    ll id = it - dp , rem = dp[id] ;
    dp[id] = A[v] ;
    auto st = lower_bound(dp,dp+n,1e16) ;
    res[v] = st -dp ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
    }
    dp[id] = rem ;
}

int main(){
    cin >> n ;
    rep(i,n) dp[i] = 1e16 ;
    rep(i,n) cin >> A[i] ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1) ;
    rep(i,n) cout << res[i] << endl ;
}