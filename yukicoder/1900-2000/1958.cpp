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

ll n , x , y ;
ll A[404040] , B[404040] ;
vector<ll> bit_a(60,0) , bit_b(60,0) ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    rep(i,x) cin >> A[i] ;
    rep(i,y) cin >> B[i] ;
    rep(i,x) rep(j,50) if(A[i] >> j & 1) bit_a[j]++ ;
    rep(i,y) rep(j,50) if(B[i] >> j & 1) bit_b[j]++ ;
    
    ll sum = 0 ;
    ll res = 0 ;

    rep(S,20){
        vector<vector<ll>> dp(n+1,vector<ll>(2,0)) ;
        dp[0][0] = 1 ;
        rep(i,n){
            (dp[i+1][1] += dp[i][0] * bit_a[S] % mod + dp[i][1] * x % mod) %= mod ;
            (dp[i+1][0] += (x - bit_a[S] + mod) % mod * dp[i][0] % mod) %= mod ;
            (dp[i+1][0] = (y - bit_b[S]) * dp[i+1][1] % mod + y * dp[i+1][0] % mod) %= mod ;
            (dp[i+1][1] *= bit_b[S]) %= mod ;
        }
        (res += (1 << S) * dp[n][1] % mod) %= mod ;
    }
    cout << res << endl ;
}