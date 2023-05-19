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
    int H[n] ;
    for(int i = 0 ; i < n ; i++) cin >> H[i] ;
    int dp[n+1] ;
    dp[0] = 0 ;
    dp[1] = abs(H[1]-H[0]) ;
    for(int i = 2 ; i < n ; i++){
        dp[i] = min(abs(H[i] - H[i-1]) + dp[i-1],abs(H[i] - H[i-2]) + dp[i-2]) ;
    }
    cout << dp[n-1] << endl ;
}