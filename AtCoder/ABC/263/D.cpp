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
#define endl "\n"

ll n , x , y ;
ll A[202020] , S[202020] ;
ll L[202020] , R[202020] ;
ll dp[202020][3] ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    rep(i,n) cin >> A[i];
    rep(i,n+1) rep(j,3) dp[i][j] = 1e17;
    dp[0][0] = 0 ;
    rep(i,n){
        chmin(dp[i+1][0],dp[i][0] + x);
        chmin(dp[i+1][1],dp[i][0] + A[i]);
        chmin(dp[i+1][1],dp[i][1] + A[i]);
        chmin(dp[i+1][2],dp[i][0] + y);
        chmin(dp[i+1][2],dp[i][1] + y);
        chmin(dp[i+1][2],dp[i][2] + y);
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl;
}