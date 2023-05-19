#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int mod = 1000000007 ;

int n , k ;
int A[105] ;
ll dp[105][100007] , S[100007] ;

int main(){
    memset(dp,0,sizeof(dp)) ;
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        S[0] = dp[i-1][0] ;
        for(int j = 1 ; j <= k ; j++) S[j] = (S[j-1] + dp[i-1][j] + mod) % mod ;
        for(int j = 0 ; j <= k ; j++){
            if(j - A[i-1] - 1 >= 0) (dp[i][j] += S[j] - S[j - A[i-1] - 1] + mod) %= mod ;
            else (dp[i][j] += S[j] + mod) %= mod ;
        }
    }
    cout << dp[n][k] << endl ;
}