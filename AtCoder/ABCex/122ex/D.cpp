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

int n ;
ll dp[101][4][4][4] ;

int main(){
    cin >> n ;
    // A : 0 , G : 1 , C : 2 , T : 3
    rep(i,4) rep(j,4) rep(k,4) dp[3][i][j][k] = 1 ;
    dp[3][0][1][2] = 0 ;
    dp[3][0][2][1] = 0 ;
    dp[3][1][0][2] = 0 ;
    rrep(s,4,n+1) rep(i,4) rep(j,4) rep(k,4) rep(m,4){
        if(i == 0 && j == 1 && k == 2) continue ;
        if(i == 0 && j == 2 && k == 1) continue ;
        if(i == 1 && j == 0 && k == 2) continue ;
        if(m == 2 && i == 0 && j == 1) continue ;
        if(m == 2 && i == 0 && k == 1) continue ;
        if(m == 2 && j == 0 && k == 1) continue ;
        if(m == 2 && j == 1 && k == 0) continue ;
        if(m == 1 && j == 0 && k == 2) continue ;
        (dp[s][j][k][m] += dp[s-1][i][j][k]) %= mod ;
    }
    ll res = 0 ;
    rep(i,4) rep(j,4) rep(k,4) (res += dp[n][i][j][k]) %= mod ;
    cout << res << endl ;
}