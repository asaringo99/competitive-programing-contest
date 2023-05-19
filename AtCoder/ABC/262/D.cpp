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
#define endl "\n"

const int mod = 998244353 ;

int n ;
ll A[101] ;
ll dp[101][101][101] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rrep(d,1,n+1){
        rep(i,n+1) rep(j,d+1) rep(k,d+1) dp[i][j][k] = 0 ;
        dp[0][0][0] = 1 ;
        rep(i,n){
            rep(j,d+1){
                rep(k,d){
                    (dp[i+1][j][k] += dp[i][j][k]) %= mod ;
                    (dp[i+1][j+1][(k+A[i])%d] += dp[i][j][k]) %= mod ;
                }
            }
        }
        (res += dp[n][d][0]) %= mod ;
    }
    cout << res << endl ;
}