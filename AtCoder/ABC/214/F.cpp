#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

string S ;
ll dp[202020] ;
int next_[202020][30] ;

void f(string S){
    int n = S.size() ;
    rep(i,26) next_[n][i] = n + 10 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 26 ; j++) next_[i][j] = next_[i+1][j] ;
        next_[i][S[i]-'a'] = i ;
    }
}

int main(){
    cin >> S ;
    int n = S.size() ;
    f(S) ;
    rep(i,26) dp[next_[0][i] + 1]++ ;
    rrep(i,1,n){
        rep(j,26){
            (dp[next_[i][j] + 1] += dp[i]) %= mod ;
        }
        dp[next_[i][S[i]-'a'] + 1] -= dp[i] ;
        (dp[next_[i][S[i]-'a'] + 1] += mod) %= mod ;
        (dp[next_[i+1][S[i]-'a']+1] += dp[i]) %= mod ;
    }
    ll res = 0 ;
    rrep(i,1,n+1) (res += dp[i]) %= mod ;
    cout << res << endl ;
}