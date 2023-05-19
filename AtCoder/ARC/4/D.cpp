#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
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

void init(){ f() ; g() ; }

ll n , m , k ;
vector<P> prime ;

int main(){
    init() ;
    cin >> n >> m ;
    k = n ;
    n = abs(n) ;
    if(abs(n) == 1) {
        cout << 1 << endl ;
        return 0 ;
    }
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        int ex = 0 ;
        while(n % i == 0){
            ex++ ;
            n /= i ;
        }
        prime.push_back(P(i,ex)) ;
    }
    if(n != 1) prime.push_back(P(n,1)) ;
    ll res = 1 ;
    rep(i,prime.size()){
        P p = prime[i] ;
        ll val = p.first , ex = p.second ;
        (res *= combination(m-1+ex,ex)) %= mod ;
    }
    int s = k < 0 ? 1 : 0 ;
    ll ans = 0 ;
    for(int i = s ; i <= m ; i += 2){
        (ans += res * combination(m,i) % mod) %= mod ;
    }
    cout << ans << endl ;
}