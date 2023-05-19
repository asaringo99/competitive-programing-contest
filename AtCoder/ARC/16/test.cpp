#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b , c ;
double dp[101][101][101] ;

double rec(int a , int b , int c){
    if(a == 100 || b == 100 || c == 100) return dp[a][b][c] = 0 ;
    if(dp[a][b][c] != 1e18) return dp[a][b][c] ;
    double val = 1 ;
    val += rec(a+1,b,c) * (double) a / (a + b + c) ;
    val += rec(a,b+1,c) * (double) b / (a + b + c) ;
    val += rec(a,b,c+1) * (double) c / (a + b + c) ;
    return dp[a][b][c] = val ;
}

int main(){
    cin >> a >> b >> c ;
    rep(i,101) rep(j,101) rep(k,101) dp[i][j][k] = 1e18 ;
    cout << setprecision(15) << rec(a,b,c) << endl ;
}