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
    int n, k, L;
    cin >> n >> L >> k;
    vector<ll> D(n+1), A(n);
    rep(i,n) cin >> D[i];
    rep(i,n) cin >> A[i];
    D[n] = L;
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1e16));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,k+1){
            rep(x,k+1){
                if(i + 1 + x > n) continue;
                if(j + x > k) continue;
                chmin(dp[i+1+x][j+x], dp[i][j] + (D[i+1+x] - D[i]) * A[i]);
            }
        }
    }
    ll res = 1e18;
    rep(i,k+1) chmin(res,dp[n][i]);
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}