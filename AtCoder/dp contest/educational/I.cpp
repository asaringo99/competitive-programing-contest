#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

double dp[3005][3005] ;
double p[3005] ;
int n ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i < n + 1 ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0) dp[i][j] = dp[i-1][j] * (1 - p[i-1]) ;
            else dp[i][j] = dp[i-1][j] * (1 - p[i-1]) + dp[i-1][j-1] * p[i-1] ;
        }
    }
    double sum = 0 ;
    for(int i = (n + 1) / 2 ; i <= n ; i++) sum += dp[n][i] ;
    cout << setprecision(15) << sum << endl ;
}