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

int n ;
ll dp[202020][3] ;
ll A[202020] , B[202020] ;

ll f(int k){
    memset(dp,0,sizeof(dp)) ;
    if(k == 0) dp[0][0] = A[0] ;
    if(k == 1) dp[0][1] = B[n-1] ;
    if(k == 2) dp[0][2] = A[0] + B[n-1] ;
    rrep(i,1,n-1){
        dp[i][0] = A[i] + max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
        dp[i][1] = B[i-1] + max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
        dp[i][2] = A[i] + B[i-1] + dp[i-1][1] ;
    }
    if(k == 0){
        dp[n-1][0] = A[n-1] + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]}) ;
        dp[n-1][1] = B[n-2] + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]}) ;
        dp[n-1][2] = A[n-1] + B[n-2] + dp[n-2][1] ;
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) ;
    }
    else if(k == 1){
        dp[n-1][0] = A[n-1] + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]}) ;
        dp[n-1][1] = B[n-2] + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]}) ;
        dp[n-1][2] = A[n-1] + B[n-2] + dp[n-2][1] ;
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) ;
    }
    else{
        dp[n-1][1] = B[n-2] + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]}) ;
        return dp[n-1][1] ;
    }
}

int main(){
    cin >> n ;
    ll res = 0 ;
    rep(i,n) cin >> A[i] , res += A[i] ;
    rep(i,n) cin >> B[i] , res += B[i] ;
    ll sum = 0 ;
    rep(i,3) chmax(sum,f(i)) ;
    cout << res - sum << endl ;
}