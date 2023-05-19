#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int H , W ;
ll dp[1010][1010] ;
char S[1010][1010] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    dp[0][0] = 1 ;
    rep(i,H) rep(j,W){
        if(i != H-1 && S[i+1][j] == '.') (dp[i+1][j] += dp[i][j]) %= mod ;
        if(j != W-1 && S[i][j+1] == '.') (dp[i][j+1] += dp[i][j]) %= mod ;
    }
    cout << dp[H-1][W-1] << endl ;
}