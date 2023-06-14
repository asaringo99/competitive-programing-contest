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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    ll n, x;
    cin >> n >> x;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    vector<vector<bool>> dp(n+1,vector<bool>(x+1,false));
    dp[0][0] = true;
    rrep(i,1,n+1){
        rep(j,x+1){
            if(dp[i-1][j]) dp[i][j] = true;
            if(dp[i][j]) if(j + A[i-1] <= x) dp[i][j+A[i-1]] = true;
        }
    }
    if(dp[n][x]) cout << "yes" << endl ;
    else cout << "no" << endl ;
}

int main(){
    fast_io
    solve();
}