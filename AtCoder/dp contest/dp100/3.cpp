#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int a , b , c ;
bool dp[303][101] ;
bool ng[303] ;

int main(){
    cin >> n >> a >> b >> c ;
    memset(ng,1,sizeof(ng)) ;
    ng[a] = 0 ;
    ng[b] = 0 ;
    ng[c] = 0 ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,100){
        if(ng[i+1]) dp[i+1][j+1] |= dp[i][j] ;
        if(ng[i+2]) dp[i+2][j+1] |= dp[i][j] ;
        if(ng[i+3]) dp[i+3][j+1] |= dp[i][j] ;
    }
    bool ok = false ;
    rep(i,101) if(dp[n][i]) ok = true ;
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}