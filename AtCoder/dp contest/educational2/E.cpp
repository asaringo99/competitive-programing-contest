#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , W ;
ll v[110] , w[110] , dp[110][100007] ;

int main(){
    cin >> n >> W ;
    rep(i,n) cin >> w[i] >> v[i] ;
    rep(i,n+1) fill(dp[i],dp[i]+100007,1e15) ;
    dp[0][0] = 0 ;
    rep(i,n) rep(j,100005){
        dp[i+1][j] = min(dp[i+1][j],dp[i][j]) ;
        dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]],dp[i][j]+w[i]) ;
    }
    ll ans = -1 ;
    rep(i,100005) if(dp[n][i] <= W) ans = i ;
    cout << ans << endl ; 
}