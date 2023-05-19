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

int n ;
ll A[202020] ;
ll dp[202020][3] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) rep(j,3) dp[i][j] = -1e16 ;
    ll res = -1 ;
    if(n % 2 == 0){
        dp[0][0] = A[0] ;
        dp[1][1] = A[1] ;
        rep(i,n){
            rep(j,2){
                chmax(dp[i+2][j],dp[i][j] + A[i+2]) ;
                if(j + 1 < 2) chmax(dp[i+3][j+1],dp[i][j] + A[i+3]) ;
            }
        }
        res = max({dp[n-1][1],dp[n-2][0]}) ;
    }
    else{
        dp[0][0] = A[0] ;
        dp[1][1] = A[1] ;
        dp[2][2] = A[2] ;
        rep(i,n){
            rep(j,3){
                chmax(dp[i+2][j],dp[i][j] + A[i+2]) ;
                if(j + 1 < 3) chmax(dp[i+3][j+1],dp[i][j] + A[i+3]) ;
                if(j + 2 < 3) chmax(dp[i+4][j+2],dp[i][j] + A[i+4]) ;
            }
        }
        res = max({dp[n-1][2],dp[n-2][1],dp[n-3][0]}) ;
    }
    cout << res << endl ;
}