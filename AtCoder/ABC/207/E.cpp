#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
ll A[3030] , dp[3030][3030] , dt[3030][3030] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    dp[1][1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            if(A[i-1] % j != 0){
                dp[i][j] = 0 ;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod ;
            }
        }
    }
    ll res = 0 ;
    for(int i = 1 ; i <= n ; i++) (res += dp[n][i]) %= mod ;
    cout << res << endl ;
}