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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

ll n , k , d;
ll A[201];
ll dp[201][201][201];

int main(){
    fast_input_output
    cin >> n >> k >> d;
    rep(i,n) cin >> A[i];
    rep(i,n+10) rep(j,k+10) rep(x,d+10) dp[i][j][x] = -1e18;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,k+1){
            rep(x,d){
                if(dp[i][j][x] == -1e18) continue;
                ll v = A[i] + x;
                ll y = v / d;
                ll m = v % d;
                chmax(dp[i+1][j][x],dp[i][j][x]);
                chmax(dp[i+1][j+1][m],dp[i][j][x] + y);
            }
        }
    }
    if(dp[n][k][0] == -1e18) cout << -1 << endl;
    else cout << dp[n][k][0] * d << endl;
}