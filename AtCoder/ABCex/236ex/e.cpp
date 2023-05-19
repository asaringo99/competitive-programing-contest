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
ll A[101010], B[101010];

bool f(ld x){
    vector<vector<ld>> dp(n+1,vector<ld>(2,-1e18));
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i,n){
        chmax(dp[i+1][0], dp[i][1]);
        chmax(dp[i+1][1], dp[i][1] + (ld)A[i] - x);
        chmax(dp[i+1][1], dp[i][0] + (ld)A[i] - x);
    }
    return max(dp[n][0],dp[n][1]) >= 0;
}

bool g(ll x){
    vector<vector<ll>> dp(n+1,vector<ll>(2,-2e9));
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i,n){
        int val = A[i] >= x ? 1 : -1;
        chmax(dp[i+1][0], dp[i][1]);
        chmax(dp[i+1][1], dp[i][1] + val);
        chmax(dp[i+1][1], dp[i][0] + val);
    }
    return max(dp[n][0],dp[n][1]) > 0;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i], B[i] = A[i];
    ld lef = 0, rig = 2e9;
    int cnt = 0;
    while(cnt <= 100){
        ld mid = (lef + rig) / 2;
        if(f(mid)) lef = mid;
        else rig = mid;
        cnt++;
    }
    cout << fixed << setprecision(10) << lef << endl;
    sort(B,B+n);
    int lf = 0, rg = n;
    while(rg - lf > 1){
        int mid = (lf + rg) / 2;
        if(g(B[mid])) lf = mid;
        else rg = mid;
    }
    cout << B[lf] << endl;
}