#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

string S ;
int n ;
ll dp[101010][4] ;

int main(){
    cin >> S ;
    n = S.size() ;
    dp[0][0] = 1 ;
    rep(i,n){
        if(S[i] == '?') {
            rep(j,4) dp[i+1][j] = 3 * dp[i][j] % mod ;
            rep(j,3) (dp[i+1][j+1] += dp[i][j]) %= mod ;
        }
        else {
            rep(j,4) dp[i+1][j] = dp[i][j] ;
            (dp[i+1][(S[i]-'A')+1] += dp[i][(S[i]-'A')]) %= mod ;
        }
    }
    cout << dp[n][3] << endl ;
}