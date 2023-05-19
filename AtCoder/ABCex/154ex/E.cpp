#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
int k ;
int dp[110][2][110] ;

int main(){
    cin >> S >> k ;
    int n = S.size() ;
    vector<int> digit ;
    for(char u : S) digit.push_back(u - '0') ;
    dp[0][0][0] = 1 ;
    int p = 0 ;
    rep(i,n){
        // 0
        if(digit[i] == 0) dp[i+1][0][p] = dp[i][0][p] ;
        if(digit[i] != 0) dp[i+1][0][p+1] = dp[i][0][p] ;
        if(digit[i] > 0) dp[i+1][1][p+1] += dp[i][0][p] * (digit[i] - 1) ;
        if(digit[i] > 0) dp[i+1][1][p] += dp[i][0][p] ;
        if(digit[i] != 0) p++ ;

        // 1
        rep(j,k) dp[i+1][1][j+1] += dp[i][1][j] * 9 ;
        rep(j,k+1) dp[i+1][1][j] += dp[i][1][j] ;
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl ;
}