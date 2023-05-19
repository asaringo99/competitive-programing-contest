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

int n , k ;
ll A[202020] ;
ll dp[202020][101] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,n+1) rep(j,70) dp[i][j] = 1e14 ;
    dp[0][0] = 0 ;
    rep(i,n) rep(j,40) {
        dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1) ;
        auto it = lower_bound(A,A+n,2*A[i]) ; it-- ;
        int id = it - A ;
        dp[id+1][j+1] = min(dp[id+1][j+1],dp[i][j]) ;
    }
    rep(i,50) if(dp[n][i] != 1e14 && dp[n][i] <= k){
        cout << i << " " << dp[n][i] << endl ;
        return 0 ;
    }
}