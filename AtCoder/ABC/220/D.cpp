#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

int n ;
ll A[101010] ;
ll dp[101010][11] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;

    dp[0][A[0]] = 1 ;
    rep(i,n-1){
        ll a = A[i+1] ;
        rep(j,10){
            (dp[i+1][(j + a) % 10] += dp[i][j]) %= mod ;
            (dp[i+1][(j * a) % 10] += dp[i][j]) %= mod ;
        }
    }
    rep(i,10) cout << dp[n-1][i] << endl ;
}