#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
bool dp[105][10007] ;
int p[105] ;

int main(){
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = true ;
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    rep(i,n) rep(j,10007){
        dp[i+1][j] |= dp[i][j] ;
        dp[i+1][j+p[i]] |= dp[i][j] ;
    }
    int res = 0 ;
    rep(i,10007) if(dp[n][i]) res++ ;
    cout << res << endl ;
}