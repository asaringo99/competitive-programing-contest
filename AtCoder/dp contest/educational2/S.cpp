#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

string S ;
vector<int> digit ;
int D ;
ll dp[10100][2][110] ;

int main(){
    cin >> S >> D ;
    int n = S.size() ;
    rep(i,n) digit.push_back(S[i] - '0') ;
    dp[0][0][0] = 1 ;
    rep(i,n){
        // smaller = false
        rep(x,digit[i]+1) rep(j,D){
            if(x < digit[i]) (dp[i+1][1][(j+x)%D] += dp[i][0][j]) %= mod ;
            else (dp[i+1][0][(j+x)%D] += dp[i][0][j]) %= mod ;
        }
        // smaller = true
        rep(x,10) rep(j,D){
            (dp[i+1][1][(j+x)%D] += dp[i][1][j]) %= mod ;
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl ;
}