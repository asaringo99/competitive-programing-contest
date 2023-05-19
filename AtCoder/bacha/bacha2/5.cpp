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

int n ;
ll A[202020] , B[202020] ;
ll S[202020] , T[202020];
ll dp[202020][6] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    rep(i,n) B[i] = A[n-1-i] , T[i+1] = T[i] + B[i] ;
    ll res = min(T[n-1],S[n-1]) ;
    rep(i,n) rep(j,6) dp[i][j] = 1e18 ;
    rep(i,n){
        dp[i][0] = S[i] ;
        dp[i][1] = S[i] + (A[i] % 2 == 0 ? 0 : 1) ;
        dp[i][4] = S[i] ;
        dp[i][3] = S[i] ;
        // 0: 片道
        if(i > 0){
            if(A[i] == 0) chmin(dp[i][0], dp[i-1][0] + 1) ;
            else if(A[i] % 2 == 0) chmin(dp[i][0], dp[i-1][0] + 1) ;
            else if(A[i] % 2 == 1) chmin(dp[i][0], dp[i-1][0]) ;
            chmin(res, dp[i][0] + T[n-1-i]) ;
        }
        // 1: 往復
        if(i > 0){
            if(A[i] == 0) chmin(dp[i][1], dp[i-1][1] + 2) ;
            else if(A[i] % 2 == 0) chmin(dp[i][1], dp[i-1][1]) ;
            else if(A[i] % 2 == 1) chmin(dp[i][1], dp[i-1][1] + 1) ;
            chmin(res, dp[i][1] + T[n-1-i]) ;
        }
        // 2: 往復後片道
        if(i > 0){
            if(A[i] == 0) {
                chmin(dp[i][2], dp[i-1][2] + 1) ;
                chmin(dp[i][2], dp[i-1][1] + 1) ;
            }
            else if(A[i] % 2 == 0){
                chmin(dp[i][2], dp[i-1][2] + 1) ;
                chmin(dp[i][2], dp[i-1][1] + 1) ;
            }
            else if(A[i] % 2 == 1){
                chmin(dp[i][2], dp[i-1][2]) ;
                chmin(dp[i][2], dp[i-1][1]) ;
            }
            chmin(res, dp[i][2] + T[n-1-i]) ;
        }
        // 3: 往復
        if(i > 0){
            if(A[i] == 0){
                chmin(dp[i][3], dp[i-1][0] + 2) ;
                chmin(dp[i][3], dp[i-1][1] + 2) ;
                chmin(dp[i][3], dp[i-1][2] + 2) ;
                chmin(dp[i][3], dp[i-1][3] + 2) ;
            }
            else if(A[i] % 2 == 0){
                chmin(dp[i][3], dp[i-1][0]) ;
                chmin(dp[i][3], dp[i-1][1]) ;
                chmin(dp[i][3], dp[i-1][2]) ;
                chmin(dp[i][3], dp[i-1][3]) ;
            }
            else if(A[i] % 2 == 1){
                chmin(dp[i][3], dp[i-1][0] + 1) ;
                chmin(dp[i][3], dp[i-1][1] + 1) ;
                chmin(dp[i][3], dp[i-1][2] + 1) ;
                chmin(dp[i][3], dp[i-1][3] + 1) ;
            }
            chmin(res, dp[i][3] + T[n-1-i]) ;
        }
        // 4: 片道
        if(i > 0){
            if(A[i] == 0){
                chmin(dp[i][4], dp[i-1][1] + 1) ;
                chmin(dp[i][4], dp[i-1][4] + 1) ;
            }
            else if(A[i] % 2 == 0){
                chmin(dp[i][4], dp[i-1][1] + 1) ;
                chmin(dp[i][4], dp[i-1][4] + 1) ;
            }
            else if(A[i] % 2 == 1) {
                chmin(dp[i][4], dp[i-1][1]) ;
                chmin(dp[i][4], dp[i-1][4]) ;
            }
            chmin(res, dp[i][4] + T[n-1-i]) ;
        }
    }
    cout << res << endl ;
}