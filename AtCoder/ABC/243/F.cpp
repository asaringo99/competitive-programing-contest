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
    return fac[n] * inv[n-r] % mod * inv[r] % mod ;
}

ll permutation(ll n , ll r){
    return fac[n] * inv[n-r] % mod ;
}

void init(){ f() ; g() ; }

int n , m , p ;
ll W[101] ;

// i番目のW, j個引く, uniqueがk個
ll dp[55][55][55] , U[55][55] ;

int main(){
    fast_input_output
    init() ;
    cin >> n >> m >> p ;
    ll S = 0 ;
    rep(i,n) cin >> W[i] , S += W[i] ;
    rep(i,n) (W[i] *= powmod(S,mod-2)) %= mod ;
    rep(i,n) rep(j,p+1) U[i][j] = powmod(W[i],j) ;

    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,p+1) rep(k,i+1) {
        (dp[i+1][j][k] += dp[i][j][k]) %= mod ;
        rrep(a,1,p+1){
            if(j + a > p) continue ;
            (dp[i+1][j+a][k+1] += dp[i][j][k] * U[i][a] % mod * inv[a] % mod) %= mod ;
        }
    }
    ll res = dp[n][p][m] * permutation(p,p) % mod ;
    cout << res << endl ;
}