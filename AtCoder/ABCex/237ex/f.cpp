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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n , m ;
ll dp[1010][12][12][12] ;

int main(){
    cin >> n >> m ;
    dp[0][m+1][m+1][m+1] = 1 ;
    rep(i,n) rrep(a,1,m+2) rrep(b,a,m+2) rrep(c,b,m+2) {
        rrep(x,1,m+1){
            if(x <= a) (dp[i+1][x][b][c] += dp[i][a][b][c]) %= mod ;
            else if(x <= b) (dp[i+1][a][x][c] += dp[i][a][b][c]) %= mod ;
            else if(x <= c) (dp[i+1][a][b][x] += dp[i][a][b][c]) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,m+1) rrep(j,i,m+1) rrep(k,j,m+1) (res += dp[n][i][j][k]) %= mod ;
    cout << res << endl ;
}