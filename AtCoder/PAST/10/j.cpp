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

const int mod = 998244353 ;
const int MAX_N = 505050 ;

ll inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll fac[MAX_N+1] ; // (n!) (mod p) を格納

// 繰り返し二乗法
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
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
    if(n < r || r < 0) return 0 ;
    return fac[n] * inv[n-r] % mod * inv[r] % mod ;
}

ll permutation(ll n , ll r){
    if(n < r || r < 0) return 0 ;
    return fac[n] * inv[n-r] % mod ;
}

void init(){ f() ; g() ; }

int n , k ;
ll A[202020] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    if(k == 1){
        cout << 0 << endl ;
        return 0 ;
    }
    init() ;
    ll pls = 0 , mns = 0 ;
    rep(i,n){
        if(i + k > n) break;
        mns += A[i] * combination(n-i-1,k-1) % mod ;
        mns %= mod ;
    }
    rep(i,n){
        if(i - k + 1 < 0) continue ;
        pls += A[i] * combination(i,k-1) % mod ;
        pls %= mod ;
    }
    ll res = (pls - mns + mod) % mod ;
    res *= powmod(combination(n,k),mod-2) ;
    res %= mod ;
    cout << res << endl ;
}