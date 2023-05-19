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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll n , c ;

ll D[404][404] , S[404][404] , A[404] , B[404] ;
ll dp[404][404] ;

int main(){
    fast_input_output
    cin >> n >> c ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rrep(i,1,401) rep(j,c+1) D[i][j] = powmod(i,j) ;
    rep(i,n){
        rep(y,c+1) {
            ll sum = 0 ;
            rrep(x,A[i],B[i]+1) (sum += D[x][y]) %= mod ;
            S[i][y] = sum ;
        }
    }
    dp[0][0] = 1 ;
    rep(i,n) rep(j,c+1){
        rep(k,c+1){
            if(j+k>c) break;
            (dp[i+1][j+k] += dp[i][j] * S[i][k] % mod) %= mod ;
        }
    }
    cout << dp[n][c] << endl ;
}