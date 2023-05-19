#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int A[1010] , C[1010] ;
int dp[1 << 20] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int b ;
        cin >> A[i] >> b ;
        int val = 0 ;
        rep(j,b){
            int c ;
            cin >> c ;
            c-- ;
            val += pow(2,c) ;
        }
        C[i] = val ;
    }
    fill(dp,dp+(1<<20),INT_MAX) ;
    dp[0] = 0 ;
    rep(i,m) rep(S,1<<n){
        if(dp[S] == INT_MAX) continue ;
        dp[S | C[i]] = min(dp[S|C[i]],dp[S]+A[i]) ;
    }
    if(dp[(1<<n)-1] == INT_MAX) cout << -1 << endl ;
    else cout << dp[(1<<n)-1] << endl ;
}