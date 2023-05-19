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

int n , k ;
int A[303] , B[303] ;

vector<int> G[303] ;
ll d[303] ;
ll cnt[303] ;
bool use[303] ;
ll dp[303][303] ;

void dfs(int v , int prev){
    if(use[v]) return ;
    use[v] = true ;
    ll res = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        res += d[u] ;
    }
    d[v] = res ;
    cnt[res]++ ;
}

int main(){
    init() ;
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll sum = 0 ;
    rep(i,n){
        rep(j,n){
            if(A[i] > A[j] && B[i] > B[j]) G[i].push_back(j) ;
        }
    }
    rep(i,n) if(!use[i]) dfs(i,-1) ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,k+1){
        dp[i+1][j] += dp[i][j] ;
        rrep(a,1,cnt[i+1]+1){
            if(j + a * (i+1) <= k) (dp[i+1][j+a*(i+1)] += dp[i][j] * combination(cnt[i+1],a) % mod) %= mod ;
        }
    }
    // rep(i,n) {
    //     rep(j,k+1) cout << dp[i][j] << " " ;
    //     cout << endl ;
    // }
    cout << dp[n][k] << endl ;
}