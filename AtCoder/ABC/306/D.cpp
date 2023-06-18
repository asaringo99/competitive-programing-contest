#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define ptv(v) for(auto u : v) cout << u << " "; cout << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

ll dp[303030][2];

void solve(){
    int n;
    cin >> n;
    bool h = false;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        if(x == 0){
            chmax(dp[i+1][0],dp[i][0]+y);
            chmax(dp[i+1][0],dp[i][1]+y);
        }
        else{
            chmax(dp[i+1][1],dp[i][0]+y);
        }
        chmax(dp[i+1][0],dp[i][0]);
        chmax(dp[i+1][1],dp[i][1]);
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}