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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> X(n);
    int y;
    rep(i,n) cin >> X[i];
    rep(i,n) cin >> y;
    vector<vector<int>> dp(n+1,vector<int>(3,-1e9));
    sort(X.begin(),X.end());
    dp[0][0] = 0;
    rep(i,n){
        chmax(dp[i+1][0], dp[i][0]);
        chmax(dp[i+1][1], dp[i][1]);
        chmax(dp[i+1][2], dp[i][2]);
        int x = X[i];
        auto it = upper_bound(X.begin(),X.end(),x+k);
        int id = it - X.begin();
        chmax(dp[id][1],dp[i][0] + (id - i));
        chmax(dp[id][2],dp[i][1] + (id - i));
    }
    cout << max(dp[n][1],dp[n][2]) << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}