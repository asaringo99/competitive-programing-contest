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
const int MAX_N = 505050 ;

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

ll n , m , b , w ;

ll ff(ll x , ll y){
    ll sum = 0 ;
    rep(i,x+1) rep(j,y+1){
        if((x-i)*(y-j) < b) continue;
        if((i + j) % 2 == 0) sum += combination((x-i)*(y-j),b) * combination(x,i) % mod * combination(y,j) % mod ;
        if((i + j) % 2 == 1) sum -= combination((x-i)*(y-j),b) * combination(x,i) % mod * combination(y,j) % mod ;
        (sum += mod) %= mod ;
    }
    (sum *= combination(n,y)) %= mod ;
    (sum *= combination(m,x)) %= mod ;
    ll wc = (n - y) * (m - x) ;
    if(wc < w) return 0 ;
    (sum *= combination(wc,w)) %= mod ;
    return sum ;
}

int main(){
    init() ;
    cin >> n >> m >> b >> w ;
    ll res = 0 ;
    rrep(i,1,m+1){
        if(i > b) continue ;
        rrep(j,1,n+1){
            res += ff(i,j) ;
            res %= mod ;
        }
    }
    cout << res << endl ;
}