#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
TP V[1010] ;
ll dp[1010][10007] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll w , s , v ;
        cin >> w >> s >> v ;
        V[i] = {w+s,w,s,v} ;
    }
    sort(V,V+n) ;
    memset(dp,-1,sizeof(dp)) ;
    dp[0][0] = 0 ;
    rep(i,n){
        ll x , w , s , v ;
        tie(x,w,s,v) = V[i] ;
        rep(j,10002){
            dp[i+1][j] = max(dp[i][j],dp[i+1][j]) ;
            if(dp[i][j] >= 0 && j <= s){
                int y = j + w <= 10000 ? j + w : 10001 ;
                dp[i+1][y] = max(dp[i+1][y],dp[i][j] + v) ;
            }
        }
    }
    ll res = 0 ;
    rep(i,10002) res = max(res,dp[n][i]) ;
    cout << res << endl ;
}