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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n;
ll X[101010];
ll Y[101010];
ll A[202020];
ll B[202020];

ll dp[202020][2];

int main(){
    fast_input_output
    cin >> n;
    rep(i,2*n) cin >> A[i];
    rep(i,2*n) cin >> B[i];
    rep(i,n) cin >> X[i];
    rep(i,n) cin >> Y[i];
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    rrep(i,1,2*n){
        if(i & 1){
            dp[i][0] = max(dp[i-1][0]+X[i/2],dp[i-1][1]+Y[i/2]) + A[i];
            dp[i][1] = max(dp[i-1][0]+Y[i/2],dp[i-1][1]+X[i/2]) + B[i];
        }
        else{
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + A[i];
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + B[i];
        }
    }
    cout << max(dp[2*n-1][0],dp[2*n-1][1]) << endl;
}