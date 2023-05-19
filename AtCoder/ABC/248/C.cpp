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
ll dp[55][3030] ;

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,k+1){
        rrep(x,1,m+1){
            if(j+x>k) continue ;
            (dp[i+1][j+x] += dp[i][j]) %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,k+1) (res += dp[n][i]) %= mod ;
    cout << res << endl ;
}