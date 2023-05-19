#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
vector<int> G[101010] ;
ll dp[101010][2] ;

void dfs(int v , int prev){
    ll w = 1 , b = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        (b *= dp[u][0]) %= mod ;
        (w *= dp[u][0] + dp[u][1]) %= mod ;
    }
    dp[v][0] = w ;
    dp[v][1] = b ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    cout << (dp[0][0] + dp[0][1]) % mod << endl ;
}