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

int n ;
string T ;
ll dp[5050][5050] ;
ll C[26] , S[26] ;

int main(){
    init() ;
    cin >> T ;
    n = T.size() ;
    rep(i,n) C[T[i]-'a']++ ;
    rep(i,26) S[i+1] = S[i] + C[i] ;
    dp[0][0] = 1 ;
    rrep(i,1,27){
        rep(j,S[i-1]+1){
            rep(k,C[i-1]+1){
                dp[i][j+k] += dp[i-1][j] * combination(j+k,j) % mod ;
                dp[i][j+k] %= mod ;
            }
        }
    }
    ll res = 0 ;
    rrep(i,1,n+1) (res += dp[26][i]) %= mod ;
    cout << res << endl ;
}