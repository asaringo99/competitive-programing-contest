#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    rep(i,n-1) A[i]++;
    rep(i,n-1){
        if(A[i+1]%A[i]==0){
            A[i+1]++;
        }
    }
    rep(i,n) cout << A[i] << " "; cout << endl;
    // vector<vector<int>> dp(n+1,vector<int>(2,1e8));
    // dp[0][0] = 0;
    // dp[0][1] = 1;
    // rrep(i,1,n){
    //     if(A[i] % A[i-1] == 0) chmin(dp[i][1],dp[i-1][0] + 1);
    //     else chmin(dp[i][0],dp[i-1][0]);
    //     if(A[i] % (A[i-1] + 1) == 0) chmin(dp[i][1],dp[i-1][1] + 1);
    //     else chmin(dp[i][0],dp[i-1][1]);
    // }
    // cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}