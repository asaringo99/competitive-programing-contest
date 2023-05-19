#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[100007] ;
ll dp[100007][2] ;

const int mod = 1000000007 ;

int main(){
    memset(dp,0,sizeof(dp)) ;
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    dp[0][0] = A[0] ;
    ll p = 1 , m = 0 ;
    rep(i,n-1){
        (dp[i+1][0] += dp[i][1] + m * A[i+1]) %= mod ;
        (dp[i+1][0] += dp[i][0] + p * A[i+1]) %= mod ;
        dp[i+1][1] = (dp[i][0] - p * A[i+1]) % mod ;
        (p += m) %= mod ;
        m = (p - m) % mod ;
    }
    cout << (dp[n-1][0] + dp[n-1][1] + mod) % mod << endl ;
}