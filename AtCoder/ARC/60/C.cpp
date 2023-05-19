#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n , A ;
ll dp[51][50 * 50 + 1][51] ;

int main(){
    cin >> n >> A ;
    ll X[n] ;
    for(int i = 0 ; i < n ; i++) cin >> X[i] ;
    //ll dp[n+1][50 * 50 + 1][n+1] ;
    
    memset(dp,0,sizeof(dp)) ;
    dp[0][0][0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 50 * 50 + 1 ; j++){
            for(int k = 0 ; k < n ; k++){
                dp[i+1][j][k] += dp[i][j][k] ;
                if(dp[i][j][k] > 0) dp[i+1][j+X[i]][k+1] += dp[i][j][k] ;
            }
        }
    }
    ll res = 0 ;
    for(ll i = 1 ; i < 50 * 50 + 1 ; i++){
        for(ll j = 1 ; j < n + 1 ; j++){
            if(j * A == i) res += dp[n][i][j] ;
        }
    }
    cout << res << endl ;
}