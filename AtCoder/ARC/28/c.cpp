#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<int> G[101010] ;
int dp[101010] ;
int res[101010] ;

void dfs(int v , int  prev){
    int ans = 1 , sum = n - 1 , val = 0 ;
    rep(i,G[v].size()){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        ans += dp[u] ;
        sum -= dp[u] ;
        chmax(val,dp[u]) ;
    }
    res[v] = max(val,sum) ;
    dp[v] = ans ;
}

void f(int v , int prev){

}

int main(){
    cin >> n ;
    rrep(i,1,n){
        int a ; cin >> a ;
        G[a].push_back(i) ;
        G[i].push_back(a) ;
    }
    dfs(0,-1) ;
    rep(i,n) cout << res[i] << endl ;
}