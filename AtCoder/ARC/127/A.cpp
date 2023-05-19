#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll dp[17][2][17];

ll rec(string S){
    int n = S.size() ;
    vector<int> dig ;
    memset(dp,0,sizeof(dp)) ;
    rep(i,n) dig.push_back(S[i] - '0') ;
    dp[0][0][0] = 0 ;
    rep(i,n){
        if(i == 0){
            if(dig[i] == 1) dp[i+1][0][1] = 1 ;
            else dp[i+1][1][1] = 1 ;
            continue;
        }        
        if(dig[i] == 1 && dp[i][0][i] == 1) dp[i+1][0][i+1] = 1 ;
        else rep(j,i+1) dp[i+1][0][j] = dp[i][0][j] ;
        rep(j,dig[i]) rep(k,i+1){
            if(j == 1 && k == i) dp[i+1][1][i+1] = dp[i][0][i] ;
            else dp[i+1][1][k] += dp[i][0][k] ;
        }
        rep(j,10) rep(k,i+1){
            if(k == i && j == 1) dp[i+1][1][i+1] += dp[i][1][i] ;
            else dp[i+1][1][k] += dp[i][1][k] ;
        }
    }
    ll res = 0 ;
    rep(i,2) rep(j,17) res += dp[n][i][j] * j ;
    return res ;
}

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    ll res = 0 ;
    string T = "" ;
    res += rec(S) ;
    rep(i,n-1){
        T += '9' ;
        res += rec(T) ;
    }
    cout << res << endl ;
}