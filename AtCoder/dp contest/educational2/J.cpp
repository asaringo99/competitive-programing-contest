#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , x , y , z ;
double dp[310][310][310] ;

double rec(int x , int y , int z){
    if(x + y + z == 0) return dp[x][y][z] = 0 ;
    if(dp[x][y][z] >= 0) return dp[x][y][z] ;
    double num = x + y + z , count = n / num ;
    if(x > 0) count += rec(x-1,y,z) * (double)x / num ;
    if(y > 0) count += rec(x+1,y-1,z) * (double)y / num ;
    if(z > 0) count += rec(x,y+1,z-1) * (double)z / num ;
    return dp[x][y][z] = count ;
}

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(a == 1) x++ ;
        if(a == 2) y++ ;
        if(a == 3) z++ ;
    }
    rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k] = -1 ;
    cout << setprecision(15) << rec(x,y,z) << endl ;
}