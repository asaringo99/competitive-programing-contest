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
int A[10101] ;
int dp[10101][2] , sp[10101][2] ;

int main(){
    cin >> n ;
    rrep(i,1,n) cin >> A[i] ;
    rep(i,n/2+1) rep(j,2) dp[i][j] = 1e9 , sp[i][j] = 1e9 ;
    dp[1][1] = 0 ;
    rrep(i,2,n+1){
        rep(j,n/2+1) rep(k,2){
            sp[j][k] = dp[j][k] ;
            dp[j][k] = 1e9 ;
        }
        rep(j,i){
            if(j > n / 2) break ;
            chmin(dp[j][0],sp[j][1]+A[i-1]) ;
            chmin(dp[j][0],sp[j][0]) ;
            chmin(dp[j+1][1],sp[j][0]+A[i-1]) ;
            chmin(dp[j+1][1],sp[j][1]) ;
        }
    }
    cout << min(dp[n/2][0],dp[n/2][1]) << endl ;
}