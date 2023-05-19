#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
ll dp[5007][5007] ;
TP A[5007] ;

int main(){
    cin >> n ;
    rep(i,n){
        int d , c ;
        ll s ;
        cin >> d >> c >> s ;
        A[i] = {d,c,s} ;
    }
    sort(A,A+n) ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 1 ; i <= n ; i++){
        int d , c ; ll s ;
        tie(d,c,s) = A[i-1] ;
        for(int j = 0 ; j <= 5001 ; j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]) ;
            if(j > 0) dp[i][j] = max(dp[i][j],dp[i][j-1]) ;
            if(j + c <= d) dp[i][j + c] = max(dp[i-1][j] + s , dp[i-1][j + c]) ;
        }
    }
    cout << dp[n][5000] << endl ;
}