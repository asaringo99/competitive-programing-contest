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

int H, W ;
char S[2020][2020];
ll R[2020], C[2020];
ll dp[2020][2020][2][2];

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) cin >> R[i];
    rep(i,W) cin >> C[i];
    rep(i,H) rep(j,W) cin >> S[i][j];
    rep(i,H) rep(j,W) rep(k,2) rep(l,2) dp[i][j][k][l] = 1e18;
    dp[0][0][0][0] = 0;
    dp[0][0][1][1] = R[0] + C[0];
    dp[0][0][0][1] = R[0];
    dp[0][0][1][0] = C[0];
    rep(i,H) rep(j,W){
        if(i + 1 < H){
            if(S[i+1][j] == S[i][j]){
                chmin(dp[i+1][j][0][1],dp[i][j][0][1] + R[i+1]);
                chmin(dp[i+1][j][1][1],dp[i][j][1][1] + R[i+1]);
                chmin(dp[i+1][j][0][0],dp[i][j][0][0]);
                chmin(dp[i+1][j][1][0],dp[i][j][1][0]);
            }
            if(S[i+1][j] != S[i][j]){
                chmin(dp[i+1][j][0][0],dp[i][j][0][1]);
                chmin(dp[i+1][j][1][0],dp[i][j][1][1]);
                chmin(dp[i+1][j][0][1],dp[i][j][0][0] + R[i+1]);
                chmin(dp[i+1][j][1][1],dp[i][j][1][0] + R[i+1]);
            }
        }
        if(j + 1 < W){
            if(S[i][j+1] == S[i][j]){
                chmin(dp[i][j+1][1][0],dp[i][j][1][0] + C[j+1]);
                chmin(dp[i][j+1][1][1],dp[i][j][1][1] + C[j+1]);
                chmin(dp[i][j+1][0][0],dp[i][j][0][0]);
                chmin(dp[i][j+1][0][1],dp[i][j][0][1]);
            }
            if(S[i][j+1] != S[i][j]){
                chmin(dp[i][j+1][0][0],dp[i][j][1][0]);
                chmin(dp[i][j+1][0][1],dp[i][j][1][1]);
                chmin(dp[i][j+1][1][0],dp[i][j][0][0] + C[j+1]);
                chmin(dp[i][j+1][1][1],dp[i][j][0][1] + C[j+1]);
            }
        }
    }
    ll res = 1e18;
    rep(i,2) rep(j,2) chmin(res,dp[H-1][W-1][i][j]);
    cout << res << endl;
}