#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int z ;

int H, W;
vector<vector<ll>> A;

void clear(){
    A.clear();
}

void solve(){
    clear();
    cin >> H >> W;
    A.resize(H,vector<ll>(W));
    rep(i,H) rep(j,W) cin >> A[i][j];
    rep(i,H) rep(j,W) A[i][j] -= (ll)i + j;
    vector<ll> vec;
    rep(i,H) rep(j,W){
        if(A[i][j] <= A[0][0]) vec.push_back(A[i][j]);
    }
    ll res = 2e18;
    for(ll u : vec){
        vector<vector<ll>> dp(H,vector<ll>(W,2e18));
        dp[0][0] = 0;
        rep(i,H) rep(j,W){
            if(A[i][j] < u) continue;
            if(i > 0) chmin(dp[i][j],dp[i-1][j]);
            if(j > 0) chmin(dp[i][j],dp[i][j-1]);
            dp[i][j] += A[i][j] - u;
        }
        chmin(res,dp[H-1][W-1]);
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}