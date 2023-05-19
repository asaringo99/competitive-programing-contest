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

int t ;

void solve(){
    int n ;
    cin >> n ;
    vector<int> A(n) ;
    rep(i,n) cin >> A[i] ;
    if(n % 2 == 1){
        ll res = 0 ;
        for(int i = 1 ; i < n ; i += 2) {
            if(max(A[i-1],A[i+1]) < A[i]) continue;
            res += max(A[i-1],A[i+1]) - A[i] + 1 ;
        }
        cout << res << endl ;
    }
    else{
        vector<vector<ll>> dp(n+1,vector<ll>(2,1e16)) ;
        dp[1][0] = A[1] > max(A[0],A[2]) ? 0 : max(A[0],A[2]) - A[1] + 1 ;
        dp[2][1] = A[2] > max(A[1],A[3]) ? 0 : max(A[1],A[3]) - A[2] + 1 ;
        rrep(i,3,n-1){
            if(i % 2 == 1){
                ll val = A[i] > max(A[i-1],A[i+1]) ? 0 : max(A[i-1],A[i+1]) - A[i] + 1 ;
                chmin(dp[i][0],dp[i-2][0] + val) ;
            }
            else{
                ll val = A[i] > max(A[i-1],A[i+1]) ? 0 : max(A[i-1],A[i+1]) - A[i] + 1 ;
                chmin(dp[i][1],dp[i-2][1] + val) ;
                chmin(dp[i][1],dp[i-3][0] + val) ;
            }
        }
        cout << min(dp[n-3][0],dp[n-2][1]) << endl ;
    }
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}