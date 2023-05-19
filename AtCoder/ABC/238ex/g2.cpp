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

int n , k ;
int p[303] , q[303] , r[303] ;
ll dp[303][303][303] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> p[i] ;
    rep(i,n) cin >> q[i] ;
    rep(i,n) r[n-p[i]] = n-q[i] ;
    dp[0][0][n] = 1 ;
    rep(i,n) rep(j,k+1) rep(x,n+1) {
        if(x < r[i]) {
            (dp[i+1][j+1][x] += dp[i][j][x]) %= mod ;
        }
        else{
            (dp[i+1][j][x] += dp[i][j][x]) %= mod ;
            (dp[i+1][j+1][r[i]] += dp[i][j][x]) %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,n+1) (res += dp[n][k][i]) %= mod ;
    cout << res << endl ;
}