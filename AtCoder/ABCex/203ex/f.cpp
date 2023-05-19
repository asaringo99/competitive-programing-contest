#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
int A[202020] , B[202020] , C[202020] ;
int dp[202020][60] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] , C[i] = A[i] ;
    sort(A,A+n) ;
    sort(C,C+n,greater<int>()) ;
    rep(i,n){
        auto it = upper_bound(A,A+n,C[i]/2) ;
        int id = it - A ;
        int cnt = n - i - id ;
        B[i] = cnt ;
    }
    rep(i,n+1) rep(j,60) dp[i][j] = 1e8 ;
    dp[0][0] = 0 ;
    rep(i,n){
        rep(j,50){
            chmin(dp[i+1][j],dp[i][j] + 1) ;
            chmin(dp[i+B[i]][j+1],dp[i][j]) ;
        }
    }
    int t = -1 , a = -1 ;
    for(int i = 50 ; i >= 0 ; i--){
        if(dp[n][i] <= k){
            t = i , a = dp[n][i] ;
        }
    }
    cout << t << " " << a << endl ;
}