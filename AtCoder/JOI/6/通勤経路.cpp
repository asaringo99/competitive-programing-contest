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

const int mod = 100000 ;

int h , w ;
ll dp[202][202][2][2] ;

int main(){
    cin >> h >> w ;
    dp[0][0][0][0] = 1 ;
    dp[0][0][1][0] = 1 ;
    rep(i,h) rep(j,w){
        if(i == 0 && j == 0) continue ;
        if(i > 0 && j > 0){
            (dp[i][j][0][1] += dp[i-1][j][0][1] + dp[i-1][j][0][0]) %= mod ;
            (dp[i][j][0][0] += dp[i-1][j][1][1]) %= mod ;
            (dp[i][j][1][1] += dp[i][j-1][1][1] + dp[i][j-1][1][0]) %= mod ;
            (dp[i][j][1][0] += dp[i][j-1][0][1]) %= mod ;
        }
        else if(i > 0) (dp[i][j][0][1] += dp[i-1][j][0][1] + dp[i-1][j][0][0]) %= mod ;
        else if(j > 0) (dp[i][j][1][1] += dp[i][j-1][1][1] + dp[i][j-1][1][0]) %= mod ;
    }
    ll res = 0 ;
    rep(i,2) rep(j,2) (res += dp[h-1][w-1][i][j]) %= mod ;
    cout << res << endl ;
}