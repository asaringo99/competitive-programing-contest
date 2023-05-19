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
const int MAX_N = 303030 ;

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
    return fac[n] * inv[r] % mod ;
}

void init(){ f() ; g() ; }

int n , m ;
map<P,bool> mp ;
ll dp[404][404] ;

ll rec(int x , int y){
    if(y - x == 1 && mp[P(x,y)]) return dp[x][y] = 1 ;
    if(dp[x][y] != -1) return dp[x][y] ;
    ll res = 0 ;
    if(mp[P(x,y)]) res += rec(x+1,y-1) ;
    for(int i = x + 1 ; i < y ; i += 2){
        if(mp[P(i+1,y)]) res += rec(x,i) * rec(i+2,y-1) % mod * combination((y-x+1)/2,(i-x+1)/2) % mod ;
        if(i + 2 == y && mp[P(i+1,y)]) res += rec(x,i) * (y-x+1)/2 % mod ;
        res %= mod ;
    }
    return dp[x][y] = res ;
}

int main(){
    init() ;
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        mp[P(a,b)] = true ;
    }
    rep(i,2*n) rep(j,2*n) dp[i][j] = -1 ;
    cout << rec(0,2*n-1) << endl ;
}