#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const ll inf = 1LL << 60 ;

ll n , x ;
ll dp[101][2] ;
ll A[101] , B[101] ;

int main(){
    cin >> n >> x ;
    rep(i,n) cin >> A[i] ;
    for(int i = n - 1 ; i >= 0 ; i--){
        ll d = x / A[i] ;
        x -= A[i] * d ;
        B[i] = d ;
    }
    dp[0][0] = B[0] ;
    dp[0][1] = A[1] / A[0] - B[0] ;
    rrep(i,1,n){
        ll m = i != n - 1 ? A[i+1] / A[i] : inf ;
        { // 0
            ll d = B[i] ;
            dp[i][0] = dp[i-1][0] + d ;
            dp[i][1] = dp[i-1][0] + m - d;
        }
        {
            ll d = B[i] + 1 ;
            dp[i][0] = min(dp[i][0],dp[i-1][1] + d) ;
            dp[i][1] = min(dp[i][1],dp[i-1][1] + m - d) ;
        }
    }
    cout << dp[n-1][0] << endl ;
}