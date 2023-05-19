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

int n , m ;

int main(){
    cin >> n >> m ;
    bool used[n+1] ;
    memset(used,0,sizeof(used)) ;
    for(int i = 0 ; i < m ; i++){
        int a ;
        cin >> a ;
        used[a] = true ;
    }
    ll dp[n+1] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0] = 1 ;
    for(int i = 1 ; i < n + 1 ; i++){
        if(used[i] && used[i-1]){
            cout << 0 << endl ;
            return 0 ;
        }
        if(used[i]) continue ;
        if(i > 1) dp[i] = dp[i-1] + dp[i-2] ;
        else dp[i] = dp[i-1] ;
        dp[i] %= mod ;
    }
    cout << dp[n] << endl ;
}