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
map<P,bool> mp ;
ll dp[404][404] ;

int n , m ;

ll rec(int a , int b){
    if(a - b == 1) return 1 ;
    if(dp[a][b] != -1) return dp[a][b] ;
    if(b - a == 1){
        if(mp[P(a,b)]) return dp[a][b] = 1 ;
        else return dp[a][b] = 0 ;
    }
    ll res = 0 ;
    if(mp[P(a,b)]) res = rec(a+1,b-1) ;
    for(int i = a + 1 ; i < b ; i += 2){
        if(mp[P(a,i)]) res += combination((b-a+1)/2,(b-i)/2) * rec(a+1,i-1) % mod * rec(i+1,b) % mod ;
        res %= mod ;
    }
    return dp[a][b] = res ;
}

int main(){
    cin >> n >> m ;
    init() ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        mp[P(a,b)] = true ;
    }
    rep(i,2*n) rep(j,2*n) dp[i][j] = -1 ;
    cout << rec(0,2*n-1) << endl ;
}