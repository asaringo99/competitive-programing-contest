#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

int n ;
ll dp[3030][3030] ;
int A[3030] , B[3030] ;
ll S[3030] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;

    rep(i,3020) S[i] = 1 ;

    rrep(i,1,n+1){
        int a = A[i-1] , b = B[i-1] ;
        rrep(j,a,b+1){
            dp[i][j] = S[j] ;
        }
        memset(S,0,sizeof(S)) ;
        S[0] = dp[i][0] ;
        rrep(j,1,3020) S[j] = (S[j-1] + dp[i][j]) % mod ;
        // rrep(j,1,5) cout << S[j - 1] << " " ;
        // cout << endl ;
    }
    ll res = 0 ;
    rrep(i,A[n-1],B[n-1]+1) (res += dp[n][i]) %= mod ;
    cout << res << endl ;
}