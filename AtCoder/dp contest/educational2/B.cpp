#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
int h[100007] , dp[101010] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> h[i] ;
    fill(dp,dp+100007,INT_MAX) ;
    dp[0] = 0 ;
    rep(i,n) rrep(j,1,k+1) dp[i+j] = min(dp[i+j],dp[i]+abs(h[i]-h[i+j])) ;
    cout << dp[n-1] << endl ;
}