#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll n ;

ll A[3] ;
ll B[3] ;
ll dp[4][5050] ;
ll ep[4][5050*5050] ;


int main(){
    fast_input_output
    cin >> n ;
    rep(i,3) cin >> A[i] ;
    rep(i,3) cin >> B[i] ;
    ll m = 0 ;
    rep(i,3){
        rep(j,n+1){
            chmax(dp[i+1][j], dp[i][j]) ;
            if(j+A[i] <= n) chmax(dp[i+1][j+A[i]], dp[i+1][j] + B[i]) , chmax(m,dp[i+1][j+A[i]]+n-j-A[i]) ;
        }
    }
    ll res = 0 ;
    rep(i,3){
        rep(j,m+1){
            chmax(ep[i+1][j], ep[i][j]) ;
            if(j+B[i] <= m) chmax(ep[i+1][j+B[i]], ep[i+1][j] + A[i]) , chmax(res,ep[i+1][j+B[i]]+m-j-B[i]) ;
        }
    }
    cout << res << endl ;
}