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

int H , W ;
ll dp[505][505][4] ;
ll A[505][505] ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) rep(k,2) dp[i][j][k] = -1 ;
    dp[0][0][0] = A[0][0] ;
    bool res = false ;
    rep(i,H) rep(j,W) rep(k,2){
        if(i == H-1 && j == W-1){
            if(dp[i-1][j][k] > A[H-1][W-1] || dp[i][j-1][k] > A[H-1][W-1]) res = true ;
            continue;
        }
        if(i-1>=0){
            if(A[i][j] < dp[i-1][j][k]) chmax(dp[i][j][k],A[i][j]+dp[i-1][j][k]) ;
            else chmax(dp[i][j][k+1],dp[i-1][j][k]) ;
        }
        if(j-1>=0){
            if(A[i][j] < dp[i][j-1][k]) chmax(dp[i][j][k],A[i][j]+dp[i][j-1][k]) ;
            else chmax(dp[i][j][k+1],dp[i][j-1][k]) ;
        }
    }
    if(res) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}