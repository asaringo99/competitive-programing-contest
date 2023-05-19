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

int n ;
ll dp[303][303][303];
int x, y;
ll T[303], H[303];

int main(){
    fast_input_output
    cin >> x >> y >> n ;
    rep(i,n) cin >> T[i] >> H[i];
    rep(i,n+1) rep(j,x+1) rep(k,y+1) dp[i][j][k] = -1e18;
    dp[0][x][y] = 0;
    rep(i,n){
        rep(j,x+1) rep(k,y+1){
            chmax(dp[i+1][j][k],dp[i][j][k]);
            if(j == 0) continue;
            if(j + k < T[i]) continue;
            if(k < T[i]) chmax(dp[i+1][j-(T[i]-k)][0],dp[i][j][k] + H[i]);
            else chmax(dp[i+1][j-1][k-T[i]+1], dp[i][j][k] + H[i]);
        }
    }
    ll res = 0;
    rep(i,x+1) rep(j,y+1) chmax(res,dp[n][i][j]);
    cout << res << endl;
}