#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int mod = 1000000007 ;

int n ;
string S ;

int main(){
    cin >> n >> S ;
    int dp[n+1][7] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 1 ; i < n + 1 ; i++){
        for(int j = 0 ; j < 7 ; j++) dp[i][j] += dp[i-1][j] ;
        if(S[i-1] == 'a') dp[i][0] += 1 ;
        if(S[i-1] == 't') dp[i][1] += dp[i-1][0] ;
        if(S[i-1] == 'c') dp[i][2] += dp[i-1][1] ;
        if(S[i-1] == 'o') dp[i][3] += dp[i-1][2] ;
        if(S[i-1] == 'd') dp[i][4] += dp[i-1][3] ;
        if(S[i-1] == 'e') dp[i][5] += dp[i-1][4] ;
        if(S[i-1] == 'r') dp[i][6] += dp[i-1][5] ;
        for(int j = 0 ; j < 7 ; j++) dp[i][j] %= mod ;
    }
    cout << dp[n][6] << endl ;
}