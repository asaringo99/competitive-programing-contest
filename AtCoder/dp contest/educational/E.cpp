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

ll n , W ;

int main(){
    cin >> n >> W ;
    ll w[n] , v[n] ;
    for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i] ;
    ll dp[n+1][100007] ;
    for(int i = 0 ; i <= n ; i++) fill(dp[i],dp[i]+100007,INT_MAX) ;
    dp[0][0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 100007 ; j++){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]) ;
            if(dp[i][j] != INT_MAX){
                int k = j + v[i] < 100007 ? j + v[i] : 100006 ;
                dp[i+1][k] = min(dp[i+1][k],dp[i][j] + w[i]) ;
            }
        }
    }
    ll res = 0 ;
    for(int i = 0 ; i < 100001 ; i++){
        if(dp[n][i] <= W) res = i ; 
    }
    cout << res << endl ;
}