#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define bit(a,b) a >> b & 1
#define dist(sx,sy,gx,gy) (sx - gx) * (sx - gx) + (sy - gy) * (sy - gy)

int n , k ;

ll X[20] , Y[20] ;
ll dp[1 << 16][16] ;

int main(){
    cin >> n >> k ;
    for(int i = 0 ; i < (1 << n) ; i++) fill(dp[i],dp[i]+16,LLONG_MAX) ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(S,1 << n) {
        ll val = 0 ;
        rep(i,n) rrep(j,i+1,n) if(bit(S,i) && bit(S,j)) val = max(val,dist(X[i],Y[i],X[j],Y[j])) ;
        dp[S][1] = val ;
    }
    for(int i = 2 ; i <= k ; i++){
        for(int S = 1 ; S < (1 << n) ; S++){
            for(int T = S ; T >= 0 ; T--){
                T &= S ;
                if(T == S || T == 0) continue ;
                dp[S][i] = min(dp[S][i],max(dp[S^T][i-1],dp[T][1])) ;
            }
        }
    }
    cout << dp[(1 << n) - 1][k] << endl ;
}