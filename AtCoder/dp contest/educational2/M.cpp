#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , k ;
ll A[100007] , dp[110][100007] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    dp[0][0] = 1 ;
    rep(i,n){
        ll S[100007] ;
        S[0] = 0 ;
        rep(j,k+1) S[j+1] = (S[j] + dp[i][j]) % mod ;
        rep(j,k+1){
            if(j - A[i] < 0) dp[i+1][j] = S[j+1] ;
            else dp[i+1][j] = (S[j+1] - S[j-A[i]] + mod) % mod ;
        }
    }
    cout << dp[n][k] << endl ;
}