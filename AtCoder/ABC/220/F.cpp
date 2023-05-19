#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<int> G[202020] ;
ll dp[202020] ;
ll dg[202020] ;
ll res[202020] ;

void dfs(int v , int prev){
    ll dist = 0 ;
    ll node = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        dist += dp[u] ;
        node += dg[u] ;
    }
    dp[v] = dist + node ;
    dg[v] = node + 1 ;
    return  ;
}

void redfs(int v , int prev){
    if(prev == -1) res[v] = dp[v] ;
    else res[v] = res[prev] + (n - dg[v]) - dg[v] ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        redfs(u,v) ;
    }
}


int main(){
    cin >> n ;
    rep(i,n-1){
        int v , u;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(u) ;
        G[u].push_back(v) ;
    }
    dfs(0,-1) ;
    redfs(0,-1) ;
    rep(i,n) cout << res[i] << endl ;
}