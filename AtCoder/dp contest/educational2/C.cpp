#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[101010][3] , dp[101010][3] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i][0] >> A[i][1] >> A[i][2] ;
    rep(i,n) rep(j,3) rep(k,3){
        if(j == k) continue ;
        dp[i+1][k] = max(dp[i+1][k],dp[i][j]+A[i][k]) ;
    }
    int res = max({dp[n][0],dp[n][1],dp[n][2]}) ;
    cout << res << endl ;
}