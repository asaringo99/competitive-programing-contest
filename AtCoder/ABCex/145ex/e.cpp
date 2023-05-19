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

int n , t ;
P A[3030] ;
ll dp[3030][3030] ;

int main(){
    cin >> n >> t ;
    rep(i,n) cin >> A[i].first >> A[i].second ;
    sort(A,A+n) ;
    rep(i,n){
        int a = A[i].first , v = A[i].second ;
        rep(j,t){
            int k = j + a >= t ? t : j + a ;
            chmax(dp[i+1][j],dp[i][j]) ;
            chmax(dp[i+1][k],dp[i][j]+v) ;
        }
        chmax(dp[i+1][t],dp[i][t]) ;
    }
    ll res = 0 ;
    rep(i,t+1) chmax(res,dp[n][i]) ;
    cout << res << endl ;
}