#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
ll A[107][6] , dp[107][6] ;

int main(){
    cin >> n ;
    rep(i,n) rep(j,6) cin >> A[i][j] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,6) rep(k,6) {
        (dp[i+1][k] += dp[i][j] * A[i][k]) %= mod ;
    }
    ll res = 0 ;
    rep(i,6){
        (res += dp[n][i]) %= mod ;
    }
    cout << res << endl ;
}