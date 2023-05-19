#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string S ;
int dp[5050][5050] ;

int main(){
    cin >> n >> S ;
    int res = 0 ;
    rrep(i,1,n+1) rrep(j,i+1,n+1){
        if(S[i-1] == S[j-1] && i + dp[i-1][j-1] < j) dp[i][j] = dp[i-1][j-1] + 1 ;
        res = max(res,dp[i][j]) ;
    }
    cout << res << endl ;
}