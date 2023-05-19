#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int x , y , n ;
ll T[303] , H[303] ;
ll dp[303][606][303] ;

int main(){
    cin >> x >> y >> n ;
    rep(i,n) cin >> T[i] >> H[i] ;
    rep(i,n){
        rep(j,y+1){
            rep(k,x+1){
                chmax(dp[i+1][j][k],dp[i][j][k]) ;
                if(j + k + T[i] > x + y) continue ;
                if(j + T[i] - 1 > y){
                    int v = T[i] - (y - j) ;
                    chmax(dp[i+1][y][k+v],dp[i][j][k]+H[i]) ;
                }
                else chmax(dp[i+1][j+T[i]-1][k+1],dp[i][j][k]+H[i]) ;
            }
        }
    }
    ll res = 0 ;
    rep(i,y+1) rep(j,x+1) chmax(res,dp[n][i][j]) ;
    cout << res << endl ;
}