#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define dist(x1,y1,x2,y2) (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
#define BIT(S,i) S >> i & 1
#define chmax(a,b) a = max(a,b)

int n , k ;
ll dp[(1 << 20) + 20][20] ;
ll X[20] , Y[20] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(S,1<<n) fill(dp[S],dp[S]+20,LLONG_MAX) ;
    rep(S,1<<n) {
        ll val = 0 ;
        rep(i,n) rrep(j,i+1,n) if(BIT(S,i) && BIT(S,j)) chmax(val,dist(X[i],Y[i],X[j],Y[j])) ;
        dp[S][1] = val ;
    }
    rrep(i,2,k+1) rrep(S,1,1<<n) for(int T = S ; T > 0 ; T = (T - 1) & S){
        if(T == S || T == 0) continue ;
        dp[S][i] = min(dp[S][i],max(dp[S^T][i-1],dp[T][1])) ;
    }
    cout << dp[(1 << n) - 1][k] << endl ;
}