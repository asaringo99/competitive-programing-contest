#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int dp[100][4010101] ;
int A[100] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    memset(dp,-1,sizeof(dp)) ;
    dp[0][1000] = 0 ;
    rrep(i,1,n+1) {
        rep(j,4000000) dp[i][j] = max(dp[i][j],dp[i-1][j]) ;
        rep(j,4000000) if(dp[i][j] > 0) dp[i][j+A[i-1]] = max(dp[i][j+A[i-1]],dp[i][j]-1) ;
        for(int j = 4000000 ; j >= 0 ; j--)
        if(j-A[i-1] >= 0 && dp[i][j] != -1) dp[i][j-A[i-1]] = max(dp[i][j-A[i-1]],dp[i][j]+1) ;
    }
    int res = 0 ;
    rep(i,4000000) if(dp[n][i] >= 0) res = i ;
    cout << res << endl ;
}