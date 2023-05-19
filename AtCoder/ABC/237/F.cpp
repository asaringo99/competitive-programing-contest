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

int n , m ;
ll dp[1010][12][12][12] ;

int main(){
    cin >> n >> m ;
    rep(i,m) dp[0][i][m][m] = 1 ;
    rrep(i,1,n){
        rep(a,m) rep(b,m+1) rep(c,m+1) rep(d,m) {
            if(d <= a) (dp[i][d][b][c] += dp[i-1][a][b][c]) %= mod ;
            if(a < d && d <= b) (dp[i][a][d][c] += dp[i-1][a][b][c]) %= mod ;
            if(b < d && d <= c) (dp[i][a][b][d] += dp[i-1][a][b][c]) %= mod ;
        }
    }
    ll res = 0 ;
    rep(a,m) rrep(b,a+1,m) rrep(c,b+1,m) (res += dp[n-1][a][b][c]) %= mod ;
    cout << res << endl ;
}