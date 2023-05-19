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

const int mod = 1000000007 ;

string L ;

int main(){
    cin >> L ;
    int n = L.size() ;
    ll dp[n+1][2] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        if(L[i] == '0') dp[i+1][0] += dp[i][0] ;
        else {
            dp[i+1][0] += 2 * dp[i][0] ;
            dp[i+1][1] += dp[i][0] ;
        }
        dp[i+1][1] += 3 * dp[i][1] ;
        dp[i+1][0] %= mod ;
        dp[i+1][1] %= mod ;
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl ;
}