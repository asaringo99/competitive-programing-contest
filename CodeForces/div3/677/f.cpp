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
ll dp[77][77][40][70];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> A[i][j];
    rep(i,n+1) rep(j,m+1) rep(s,m/2+1) rep(t,k) dp[i][j][s][t] = -1e18;
    dp[0][0][0][0] = 0;
    rep(i,n){
        rep(j,m){
            int a = A[i][j];
            rep(s,m/2+1){
                rep(t,k){
                    chmax(dp[i][j+1][s][t], dp[i][j][s][t]);
                    chmax(dp[i][j+1][s+1][(t+a)%k], dp[i][j][s][t] + a);
                }
            }
            rep(s,m/2+1) rep(t,k) chmax(dp[i+1][0][0][t],dp[i][m][s][t]);
        }
    }
    cout << dp[n][0][0][0] << endl;
}

int main(){
    fast_input_output
    solve();
}