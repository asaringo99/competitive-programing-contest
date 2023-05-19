#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , W ;
ll dp[210][10010] ;
int A[10010] , S[10010] ;

int main(){
    cin >> n >> W ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,n) S[i] = A[i] + (i == 0 ? 0 : S[i-1]) ;
    if(S[n-1] <= W){
        cout << 1 << endl ;
        return 0 ;
    }
    dp[0][0] = 1 ;
    ll res = 0 ;
    rep(i,n){
        rep(j,W+1) if(j+S[n-1-i]-A[n-1-i] <= W && j+S[n-1-i] > W) (res += dp[i][j]) %= mod ;
        rep(j,W+1){
            dp[i+1][j] += dp[i][j] ;
            if(j+A[n-1-i] <= W) (dp[i+1][j+A[n-1-i]] += dp[i][j]) %= mod ;
        }
    }
    cout << res << endl ;
}