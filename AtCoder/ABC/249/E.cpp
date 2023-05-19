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

int mod ;
const int MAX_N = 505050 ;

ll inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll fac[MAX_N+1] ; // (n!) (mod p) を格納

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void f(){
    inv[0] = 1 ; inv[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        inv[i] = powmod(i,mod-2) * inv[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void g(){
    fac[0] = 1 ; fac[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        fac[i] = (fac[i-1] * i) % mod ;
    }
}

//nCrの計算
ll combination(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] % mod * inv[r] % mod ;
}

ll permutation(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] % mod ;
}

void init(){ f() ; g() ; }

int n ;

ll dp[3030][3030] ;
ll S[3030] ;

int main(){
    fast_input_output
    cin >> n >> mod ;
    dp[0][0] = 1 ;
    dp[1][0] = -1 ;
    rep(i,n) rep(j,n) {
        ll val = i == 0 ? 26 : 25 ;
        if(i + 1 <= n){
            (dp[i+1][j+2] += dp[i][j] * val) %= mod ;
        }
        if(i + 10 <= n){
            ((dp[i+10][j+2] -= (dp[i][j] * val % mod)) += mod) %= mod ;
            (dp[i+10][j+3] += dp[i][j] * val) %= mod ;
        }
        if(i + 100 <= n){
            ((dp[i+100][j+3] -= (dp[i][j] * val % mod)) += mod) %= mod ;
            (dp[i+100][j+4] += dp[i][j] * val) %= mod ;
        }
        if(i + 1000 <= n){
            ((dp[i+1000][j+4] -= (dp[i][j] * val % mod)) += mod) %= mod ;
            (dp[i+1000][j+5] += dp[i][j] * val) %= mod ;
        }
        (dp[i+1][j] += dp[i][j]) %= mod ;
    }
    ll res = 0 ;
    rep(i,n) (res += dp[n][i]) %= mod ;
    cout << res << endl ;
}