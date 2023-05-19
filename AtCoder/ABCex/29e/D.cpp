#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
ll dp[10][2][2] ;
vector<int> digit ;

int main(){
    cin >> S ;
    int n = S.size() ;
    for(int i = 0 ; i < n ; i++) digit.push_back(S[i] - '0') ;
    dp[0][0][0] = 1 ;
    ll val = 0 ;
    for(int i = 0 ; i < n ; i++){
        // 0
        if(digit[i] == 1) dp[i+1][0][1]++ ;
        else dp[i+1][0][0] = dp[i][0][0] ;
        dp[i+1][0][1] += dp[i][0][1] ;
        for(int x = 0 ; x < digit[i] ; x++){
            if(x == 1) dp[i+1][1][1]++ ;
            else dp[i+1][1][0] += dp[i][0][0] ;
            dp[i+1][1][1] += dp[i][0][1] ;
        }

        // 1
        for(int x = 0 ; x < 10 ; x++){
            if(x == 1) if(i != 0) dp[i+1][1][1] += val ;
            else dp[i+1][1][0] += dp[i][1][0] ;
            dp[i+1][1][1] += dp[i][1][1] ;
        }
        val = val * 10 + digit[i] ;
    }
    cout << dp[n][0][1] + dp[n][1][1] << endl ;
}