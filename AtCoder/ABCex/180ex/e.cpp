#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define chmin(a,b) a = min(a,b)
#define endl "\n"

int n ;
ll X[20] , Y[20] , Z[20] ;
ll dp[1<<20][20] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] >> Z[i] ;
    rep(i,1<<n) rep(j,n) dp[i][j] = 1e16 ;
    dp[0][0] = 0 ;
    rep(S,1<<n){
        rep(i,n) rep(j,n) if(!(S >> j & 1)) if(i != j){
            chmin(dp[S | 1 << j][j],dp[S][i] + abs(X[i]-X[j]) + abs(Y[i]-Y[j]) + max(0LL,Z[j]-Z[i])) ;
        }
    }
    cout << dp[(1<<n)-1][0] << endl ;
}