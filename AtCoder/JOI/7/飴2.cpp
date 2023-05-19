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
ll A[3030] ;
ll dp[3030][3030] , S[3030][3030] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ; 
    rrep(i,1,n+1){
        rep(j,i){
            int x = i - k < 0 ? 0 : i - k ;
            chmax(dp[i][j],S[j][x]+A[i-1]) ;
        }
        rep(j,i){
            S[i][j] = j == 0 ? dp[i][j] : max(S[i][j-1],dp[i][j]) ;
        }
        rep(j,i+1){
            S[j][i] = max(S[j][i-1],S[j][i]) ;
        }
    }
    ll res = 0 ;
    rep(i,n+1) rep(j,n+1) chmax(res,dp[i][j]) ;
    cout << res << endl ;
}