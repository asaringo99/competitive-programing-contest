#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define chmin(a,b) a = min(a,b)
#define endl "\n"

int n , m ;
int A[1010] , B[1010] ;
ll dp[1010][1010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,m) cin >> B[i] ;
    rep(i,n+1) rep(j,m+1) dp[i][j] = 1e16 ;
    dp[0][0] = 0 ;
    rep(i,n+1){
        rep(j,m+1){
            chmin(dp[i+1][j],dp[i][j]+1) ;
            chmin(dp[i][j+1],dp[i][j]+1) ;
            if(A[i] != B[j]) chmin(dp[i+1][j+1],dp[i][j]+1);
            if(A[i] == B[j]) chmin(dp[i+1][j+1],dp[i][j]);
        }
    }
    cout << dp[n][m] << endl ;
}