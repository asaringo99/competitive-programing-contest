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

int n;
ll A[202020], B[202020];
ll c;

ll dp[202020][2];

void solve(){
    cin >> n >> c;
    rep(i,n-1) cin >> A[i];
    rep(i,n-1) cin >> B[i];
    rep(i,n+1) rep(j,2) dp[i][j] = 1e18;
    dp[0][0] = 0;
    rep(i,n-1){
        chmin(dp[i+1][0],dp[i][0]+A[i]);
        chmin(dp[i+1][0],dp[i][0]+B[i]+c);
        chmin(dp[i+1][0],dp[i][1]+B[i]+c);
        chmin(dp[i+1][1],dp[i][0]+B[i]);
        chmin(dp[i+1][1],dp[i][1]+B[i]);
    }
    rep(i,n) cout << dp[i][0] << " "; cout << endl;
}

int main(){
    fast_input_output
    solve();
}