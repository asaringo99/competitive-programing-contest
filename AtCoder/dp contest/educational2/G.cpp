#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int dp[101010] ;
vector<int> G[101010] ;

int rec(int s , int v){
    if(G[v].size() == 0) return dp[v] = 0 ;
    if(dp[v] >= 0) return dp[v] ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        res = max(res,rec(s,u)) ;
    }
    return dp[v] = res + 1 ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
    }
    memset(dp,-1,sizeof(dp)) ;
    int res = -1 ;
    rep(i,n) res = max(res,rec(i,i)) ;
    cout << res << endl ;
}