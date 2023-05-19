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

int n , k ;

int main(){
    cin >> n >> k ;
    int h[n] ;
    for(int i = 0 ; i < n ; i++) cin >> h[i] ;
    int dp[n] ;
    fill(dp,dp+n,INT_MAX) ;
    dp[0] = 0 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j <= k ; j++){
            if(j > i) continue ;
            dp[i] = min(dp[i],abs(h[i] - h[i-j]) + dp[i-j]) ;
        }
    }
    cout << dp[n-1] << endl ;
}