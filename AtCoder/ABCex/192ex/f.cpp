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

ll n , x ;
ll A[101] ;

int main(){
    cin >> n >> x ;
    rep(i,n) cin >> A[i] ;
    ll res = 1e18 ;
    rrep(k,1,n+1){
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k,vector<ll>(k+1,-1))) ;
        dp[0][0][0] = 0 ;
        rep(i,n) rep(j,k) rep(t,k+1) if(dp[i][j][t] >= 0) {
            chmax(dp[i+1][j][t],dp[i][j][t]) ;
            if(t + 1 <= k) chmax(dp[i+1][(j+A[i])%k][t+1], dp[i][j][t] + A[i]) ;
        }
        ll sum = dp[n][x%k][k] ;
        if(sum == -1) continue ;
        chmin(res,(x-sum)/k) ;
    }
    cout << res << endl ;
}