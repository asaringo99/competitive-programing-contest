#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll dp[2020][2020] ;
P A[2020] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        A[i] = P(-a,b) ;
    }
    sort(A,A+n) ;
    rep(i,n+1) rep(j,n+1) dp[i][j] = -1e16 ;
    dp[0][1] = 0 ;
    rep(i,n) {
        auto [c,v] = A[i] ;
        c = -c ;
        rep(j,n+1) {
            chmax(dp[i+1][j],dp[i][j]) ;
            if(j > 0) {
                int k = j - 1 + c > n ? n : j - 1 + c ;
                chmax(dp[i+1][k],dp[i][j]+v) ;
            }
        }
    }
    ll res = 0 ;
    rep(i,n+1) chmax(res,dp[n][i]) ;
    cout << res << endl ;
}