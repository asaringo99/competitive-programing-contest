#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int mod = 1000000007 ;

int H , W ;
char A[1005][1005] ;
int dp[1005][1005] ;

int main(){
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W){
        if(i + 1 < H && A[i+1][j] == '.') (dp[i+1][j] += dp[i][j]) %= mod ;
        if(j + 1 < W && A[i][j+1] == '.') (dp[i][j+1] += dp[i][j]) %= mod ;
    }
    cout << dp[H-1][W-1] << endl ;
}