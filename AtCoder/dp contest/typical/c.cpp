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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        n >>= 1 ;
        x *= x ;
    }
    return res ;
}

int n ;
ld R[2020] ;
ld dp[2020][20] ;
bool use[2020][2020] ;
ld W[2020][2020] ;

int main(){
    cin >> n ;
    rep(i,1<<n) cin >> R[i] ;
    rep(i,1<<n) rep(j,1<<n) if(i != j) W[i][j] = 1 / (1 + pow(10,(R[j]-R[i])/400)) ;
    rep(i,1<<n) dp[i][0] = 1 , use[i][i] = true ;
    rep(t,n){
        ll div = powll(2,t+1) ;
        rep(i,1<<n){
            int l = i / div * div , r = l + div ;
            rrep(j,l,r){
                if(use[i][j]) continue ;
                use[i][j] = true ;
                dp[i][t+1] += dp[i][t] * dp[j][t] * W[i][j] ;
            }
        }
    }
    rep(i,1<<n) cout << fixed << setprecision(25) << dp[i][n] << endl ;
}