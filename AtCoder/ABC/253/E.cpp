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

ll n , m , k ;
ll dp[1010][5050] , S[5050] ;

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    rrep(i,1,m+1) dp[0][i] = 1 ;
    rrep(i,1,n){
        rep(j,m) S[j+1] = (S[j] + dp[i-1][j+1]) % mod ;
        rrep(j,1,m+1){
            if(j - k >= 0) (dp[i][j] += S[j-k]) %= mod ;
            if(j + k <= m) (dp[i][j] += (S[m] - S[j+k-1] + mod)) %= mod ;
            if(k == 0) dp[i][j] -= (S[j] - S[j-1] + mod) ;
            (dp[i][j] += mod) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,m+1) (res += dp[n-1][i]) %= mod ;
    cout << res << endl ;
}