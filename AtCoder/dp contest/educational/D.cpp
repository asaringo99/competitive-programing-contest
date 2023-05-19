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

ll n , w ;

int main(){
    cin >> n >> w ;
    ll W[n] , V[n] ;
    for(int i = 0 ; i < n ; i++) cin >> W[i] >> V[i] ;
    ll dp[n+1][w+1] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 1 ; i < n + 1 ; i++){
        for(int j = 0 ; j < w + 1 ; j++){
            dp[i][j] = dp[i-1][j] ;
            if(j < W[i-1]) continue ;
            dp[i][j] = max(dp[i][j],dp[i-1][j-W[i-1]] + V[i-1]) ;
        }
    }
    cout << dp[n][w] << endl ;
}