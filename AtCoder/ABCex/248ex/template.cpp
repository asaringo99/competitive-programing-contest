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

int n , mod ;
ll dp[3030][3030][2] ;

int main(){
    fast_input_output
    cin >> n >> mod ;
    dp[0][0][1] = 1 ;
    dp[0][1][0] = 1 ;
    rrep(i,1,n) rep(j,n) {
        (dp[i][j][1] += dp[i-1][j][0]) %= mod ;
        (dp[i][j][1] += dp[i-1][j][1]) %= mod ;
        if(j>0) (dp[i][j][1] += 3 * dp[i-1][j-1][1]) %= mod ;
        if(j>0) (dp[i][j][0] += dp[i-1][j-1][0]) %= mod ;
        if(j>1) (dp[i][j][0] += 2 * dp[i-1][j-2][1]) %= mod ;
    }
    rrep(i,1,n) cout << dp[n-1][i][1] << " " ; cout << endl ;
}