#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll H , W , C ;
ll A[1010][1010] ;
ll dp[1010][1010] ;

int main(){
    cin >> H >> W >> C ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    ll res = 1e16 ;
    rep(i,H) rep(j,W) dp[i][j] = A[i][j] ;
    rep(i,H) rep(j,W){
        if(i + 1 < H){
            res = min(res,A[i+1][j]+dp[i][j]+C) ;
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]+C) ;
        }
        if(j + 1 < W){
            res = min(res,A[i][j+1]+dp[i][j]+C) ;
            dp[i][j+1] = min(dp[i][j+1],dp[i][j]+C) ;
        }
    }
    rep(i,H) rep(j,W) dp[i][j] = A[i][j] ;
    rep(i,H) for(int j = W - 1 ; j >= 0 ; j--){
        if(i + 1 < H){
            res = min(res,A[i+1][j]+dp[i][j]+C) ;
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]+C) ;
        }
        if(j - 1 >= 0){
            res = min(res,A[i][j-1]+dp[i][j]+C) ;
            dp[i][j-1] = min(dp[i][j-1],dp[i][j]+C) ;
        }
    }
    cout << res << endl ;
}