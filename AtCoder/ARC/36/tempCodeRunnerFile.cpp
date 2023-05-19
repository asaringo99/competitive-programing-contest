#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
string S ;
ll dp[303][303][303] ;

int main(){
    cin >> n >> k >> S ;
    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,k+1) rep(p,j+1){
        if(S[i] == '0' || S[i] == '?'){
            if(p == 0) dp[i+1][j+1][0] += dp[i][j][p] ;
            else dp[i+1][j][p-1] += dp[i][j][p] ;
        }
        if(S[i] == '1' || S[i] == '?'){
            if(p == j) dp[i+1][j+1][j+1] += dp[i][j][p] ;
            else dp[i+1][j][p+1] += dp[i][j][p] ;
        }
    }
    ll res = 0 ;
    rep(i,k+1) rep(j,k+1) res += dp[n][i][j] ;
    cout << res << endl ; 
}