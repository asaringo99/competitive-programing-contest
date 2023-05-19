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

int H , W ;
char C[101][101] ;
int dp[101][101] ;

int rec(int x , int y){
    if(dp[x][y] != -1) return dp[x][y] ;
    int res = 0 ;
    if(x + 1 < H && C[x+1][y] == '.' && rec(x+1,y) == 0) res = 1 ;
    if(y + 1 < W && C[x][y+1] == '.' && rec(x,y+1) == 0) res = 1 ;
    if(x + 1 < H && y + 1 < W && C[x+1][y+1] == '.' && rec(x+1,y+1) == 0) res = 1 ;
    return dp[x][y] = res ;
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    rep(i,H) rep(j,W) dp[i][j] = -1 ;
    int res = rec(0,0) ;
    if(res == 1) cout << "First" << endl ;
    if(res == 0) cout << "Second" << endl ;
}