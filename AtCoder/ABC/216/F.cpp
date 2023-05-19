#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;

int n ;
P A[5050] ;
ll dp[5050][5050] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i].first ;
    rep(i,n) cin >> A[i].second ;
    sort(A,A+n) ;
    ll ans = 0 ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,5050){
        ll a = A[i].first , b = A[i].second ;
        (dp[i+1][j] += dp[i][j]) %= mod ;
        if(j + b < 5050) {
            (dp[i+1][j+b] += dp[i][j]) %= mod ;
            if(j + b <= a) (ans += dp[i][j]) %= mod ;
        }
    }
    cout << ans << endl ;
}