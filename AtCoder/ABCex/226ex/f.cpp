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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

const ll mod = 998244353 ;
const ll MAX_N = 505050 ;

ll inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll fac[MAX_N+1] ; // (n!) (mod p) を格納

// 繰り返し二乗法
ll powmod(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
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

ll n , x ;

unordered_map<ll,ll> dp[55][55] ;

int main(){
    init() ;
    cin >> n >> x ;

    dp[0][0][1] = 1 ;
    rep(i,n+1) rep(j,n+1) for(auto it : dp[i][j]){
        ll l = it.first ;
        ll d = it.second ;
        rrep(k,1,n+1){
            if(n-j >= k) (dp[i+1][j+k][lcm(l,k)] += dp[i][j][l] * combination(n-j,k) % mod * permutation(k-1,k-1) % mod) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,n+1){
        for(auto it : dp[i][n]){
            ll l = it.first ;
            ll d = it.second ;
            (res += powmod(l,x) * d % mod * powmod(permutation(i,i),mod-2)) %= mod ;
        }
    }
    cout << res << endl ;
}