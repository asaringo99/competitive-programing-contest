#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , W ;
ll v[100007] , w[100007] , dp[110][100007] ;

int main(){
    cin >> n >> W ;
    rep(i,n) cin >> w[i] >> v[i] ;
    rep(i,n) rep(j,W+1){
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]) ;
        if(j+w[i] > W) continue ;
        dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]) ;
    }
    cout << dp[n][W] << endl ;
}