#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int h[100007] ;
int dp[100007] ;

int main(){
    fill(dp,dp+100007,INT_MAX) ;
    cin >> n ;
    rep(i,n) cin >> h[i] ;
    dp[0] = 0 ;
    rep(i,n){
        dp[i+1] = min(dp[i+1],dp[i] + abs(h[i] - h[i+1])) ;
        dp[i+2] = min(dp[i+2],dp[i] + abs(h[i] - h[i+2])) ;
    }
    cout << dp[n-1] << endl ;
}