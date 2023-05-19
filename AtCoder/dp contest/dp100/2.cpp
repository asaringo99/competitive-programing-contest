#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

ll dp[2020202] ;

int main(){
    cin >> n ;
    fill(dp,dp+2020202,1) ;
    rrep(i,1,n+1){
        int t = i ;
        string s = to_string(i) ;
        rep(j,s.size()) t += (s[j] - '0') ;
        dp[t] += dp[i] ;
    }
    cout << dp[n] << endl ;
}