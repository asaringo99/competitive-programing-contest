#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
double dp[3030][3030] ;
double p[3030] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,i+1){
        dp[i+1][j] += dp[i][j] * (1 - p[i]) ;
        dp[i+1][j+1] += dp[i][j] * p[i] ;
    }
    double res = 0 ;
    rrep(i,(n+1)/2,n+1) res += dp[n][i] ;
    cout << setprecision(15) << res << endl ;
}