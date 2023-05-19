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

int n ;
ll dp[1010101][20] ;

int main(){
    cin >> n ;
    rrep(i,1,10) dp[0][i] = 1 ;
    rep(i,n-1){
        rrep(x,1,10){
            (dp[i+1][x] += dp[i][x]) %= mod ;
            (dp[i+1][x+1] += dp[i][x]) %= mod ;
            (dp[i+1][x-1] += dp[i][x]) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,10) (res += dp[n-1][i]) %= mod ;
    cout << res << endl ;
}