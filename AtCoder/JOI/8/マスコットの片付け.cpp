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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

const int mod = 1000000007 ;
const int MAX_N = 1010101;

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

int H , W , n ;
ll dp[3030][3030] ;

ll rec(int x , int y){
    if(x == H && y == W) return dp[x][y] = 1 ;
    if(dp[x][y] != -1) return dp[x][y] ;
    ll res = 0 ;
    if(x + 1 <= H) res += rec(x+1,y) * permutation(y,y) % mod ;
    if(y + 1 <= W) res += rec(x,y+1) * permutation(x,x) % mod ;
    res %= mod ;
    return dp[x][y] = res ;
}

int main(){
    init() ;
    int sx = 1e9 , sy = 1e9 , bx = 0 , by = 0 ;
    cin >> H >> W >> n ;
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        chmin(sx,x) ;
        chmin(sy,y) ;
        chmax(bx,x) ;
        chmax(by,y) ;
    }
    int dx = bx - sx + 1 ;
    int dy = by - sy + 1 ;
    rep(i,H+1) rep(j,W+1) dp[i][j] = -1 ;
    ll res = 1 ;
    rep(i,dx*dy-n) (res *= (dx*dy-n-i)) %= mod ;
    cout << rec(dx,dy) * combination(H-dx,H-bx) % mod * combination(W-dy,W-by) % mod * res % mod << endl ;
}