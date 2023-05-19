#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    int a[n] , b[n] , c[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] >> c[i] ;
    int dp[n+1][3] ;
    dp[0][0] = 0 ;
    dp[0][1] = 0 ;
    dp[0][2] = 0 ;
    for(int i = 1 ; i < n + 1 ; i++){
        dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + a[i-1] ;
        dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + b[i-1] ;
        dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + c[i-1] ;
    }
    int res = 0 ;
    for(int i = 0 ; i < 3 ; i++){
        res = max(dp[n][i],res) ;
    }
    cout << res << endl ;
}