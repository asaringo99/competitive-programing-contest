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

int n ;
ll x ;
ll A[101] ;
ll dp[101][101][101] ;

int main(){
    fast_input_output
    cin >> n >> x ;
    rep(i,n) cin >> A[i] ;
    ll res = 1e18 + 10 ;
    rrep(a,1,n+1){
        rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k] = -1 ;
        dp[0][0][0] = 0 ;
        rep(i,n) rep(j,a) rep(k,i+1){
            if(dp[i][j][k] == -1) continue ;
            chmax(dp[i+1][(j+A[i])%a][k+1],dp[i][j][k]+A[i]) ;
            chmax(dp[i+1][j][k],dp[i][j][k]) ;
        }
        ll val = dp[n][x%a][a] ;
        if(val == -1) continue ;
        chmin(res,(x-val)/a) ;
    }
    cout << res << endl ;
}