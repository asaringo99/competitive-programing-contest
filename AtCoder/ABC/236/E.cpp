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
ll A[101010] ;

bool f(ld x){
    vector<vector<ld>> dp(n+1,vector<ld>(2,-1e18)) ;
    dp[0][0] = 0 ;
    dp[0][1] = A[0] - x ;
    rrep(i,1,n){
        dp[i][0] = max(dp[i][0],dp[i-1][1]) ;
        dp[i][1] = max(dp[i][1],dp[i-1][0] + (ld)A[i] - x) ;
        dp[i][1] = max(dp[i][1],dp[i-1][1] + (ld)A[i] - x) ;
    }
    if(dp[n-1][0] >= 0 || dp[n-1][1] >= 0) return true ;
    return false ;
}

bool g(ll x){
    vector<vector<ll>> dp(n+1,vector<ll>(2,0)) ;
    dp[0][0] = 0 ;
    dp[0][1] = A[0] >= x ? 1 : -1 ;
    rrep(i,1,n){
        dp[i][0] = dp[i-1][1] ;
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + (A[i] >= x ? 1 : -1) ;
    }
    if(dp[n-1][0] > 0 || dp[n-1][1] > 0) return true ;
    return false ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ld lef = 0 , rig = 1e10 ;
    int count = 0 ;
    while(count < 100){
        ld mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
        count++ ;
    }
    cout << fixed << setprecision(15) << lef << endl ;
    ll down = 0 , up = 1e10 ;
    while(up - down > 1){
        ll mid = (up + down) / 2 ;
        if(g(mid)) down = mid ;
        else up = mid ;
    }
    cout << down << endl ;
}