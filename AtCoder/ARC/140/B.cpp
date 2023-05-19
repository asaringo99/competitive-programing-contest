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

ll n , m ;
ll dp[101][101] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    int b = -1 ;
    rep(i,60) if(m >> i & 1) b = i ;
    // cout << b << endl ;
    if(n > b + 1){
        cout << 0 << endl ;
        return 0 ;
    }
    dp[0][0] = 1 ;
    rep(i,b+1) rep(j,n){
        rrep(k,i+1,b+2){
            if(k == b+1){
                ll s = (1LL << b) ^ m ;
                s++ ;
                s %= mod ;
                (dp[k][j+1] += dp[i][j] * s % mod) %= mod ;
            }
            else (dp[k][j+1] += dp[i][j] * powmod(2,k-1) % mod) %= mod ;
        }
    }
    ll res = 0 ;
    // rep(i,b+2){
    //     rep(j,n+1) cout << dp[i][j] << " " ; cout << endl ;
    // }
    rep(i,b+2) (res += dp[i][n]) %= mod ;
    cout << res << endl ;
}