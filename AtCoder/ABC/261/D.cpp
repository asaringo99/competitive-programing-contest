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
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll X[5050] , C[5050] , Y[5050] ;
ll dp[5050][5050] ;

int main(){
    fast_input_output
    cin >> n >> m;
    rep(i,n) cin >> X[i] ;
    rep(i,m) {
        ll c , x ;
        cin >> c >> x ; 
        C[c] += x ;
    }
    rep(i,n){
        rep(j,i+1){
            chmax(dp[i+1][j+1] , dp[i][j] + C[j+1] + X[i]) ;
            chmax(dp[i+1][0],dp[i][j]) ;
        }
    }
    ll res = 0 ;
    rep(i,n+1) chmax(res,dp[n][i]) ;
    cout << res << endl ;
}