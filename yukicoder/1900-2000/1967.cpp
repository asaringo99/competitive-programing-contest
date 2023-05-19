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

const int mod = 998244353 ;
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n , k ;
ll dp[2020][2020] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    dp[0][0] = 1 ;
    rep(i,k){
        rep(j,n+1) {
            ll rem = n - j ;
            ll val = powmod(rem,mod-2) ;
            dp[i+1][j+1] += dp[i][j] * val % mod ;
            dp[i+1][n+1] -= dp[i][j] * val % mod ;
            dp[i+1][j+1] %= mod ;
            dp[i+1][n+1] += mod ;
            dp[i+1][n+1] %= mod ;
        }
        rep(j,n+2) (dp[i+1][j+1] += dp[i+1][j]) %= mod ;
    }
    ll res = 0 ;
    rep(i,k+1) (res += dp[i][n]) %= mod ;
    cout << res << endl ;
}