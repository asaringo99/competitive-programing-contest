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

int n ;
ll dp[1010][10101];

int main(){
    cin >> n ;
    vector<tuple<ll,ll,ll>> A(n);
    rep(i,n){
        int w, s, v;
        cin >> w >> s >> v;
        A[i] = {w,s,v};
    }
    vector<pair<ll,int>> X(n);
    rep(i,n){
        auto [w,s,v] = A[i];
        X[i] = {w+s,i};
    }
    sort(all(X),greater<pair<ll,int>>());
    rep(i,n+1) rep(j,10101) dp[i][j] = -1e18;
    rep(i,n){
        auto [sw, id] = X[i];
        auto [w, s, v] = A[id];
        chmax(dp[i+1][s], v);
        rep(j,10101){
            chmax(dp[i+1][j],dp[i][j]);
            if(j >= w) chmax(dp[i+1][min(s,j-w)],dp[i][j]+v);
        }
    }
    ll res = 0;
    rep(i,10101) chmax(res,dp[n][i]);
    cout << res << endl;
}