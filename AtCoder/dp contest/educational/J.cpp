#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
int X , Y , Z ;
double dp[301][301][301] ;

double E(int i , int j , int k){
    if(i == 0 && j == 0 && k == 0) return dp[0][0][0] = 0 ;
    if(dp[i][j][k] >= 0) return dp[i][j][k] ;
    double m = i + j + k ;
    double val = n / m ;
    if(i > 0) val += E(i - 1 , j , k) * (double)i / m ;
    if(j > 0) val += E(i + 1 , j - 1 , k) * (double)j / m ;
    if(k > 0) val += E(i , j + 1 , k - 1) * (double)k / m ;
    return dp[i][j][k] = val ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> n ;
    X = 0 , Y = 0 , Z = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(a == 1) X++ ;
        if(a == 2) Y++ ;
        if(a == 3) Z++ ;
    }
    cout << setprecision(15) << E(X,Y,Z) << endl ;
}