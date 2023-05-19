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

int z;
int n;
vector<int> A;

bool f(int x){
    vector<vector<int>> dp(n+1,vector<int>(x+1,1e9));
    dp[0][0] = 0;
    rep(i,n){
        int a = A[i];
        rep(j,x+1){
            if(dp[i][j] == 1e9) continue;
            if(j + a <= x) chmin(dp[i+1][j+a],max(dp[i][j],j+a));
            if(j - a <= 0 && dp[i][j] + abs(j - a) <= x) chmin(dp[i+1][0],dp[i][j]+abs(j-a));
            else if(j - a >= 0) chmin(dp[i+1][j-a],dp[i][j]);
        }
    }
    rep(i,x+1) if(dp[n][i] != 1e9) return true;
    return false;
}

void solve(){
    cin >> n;
    A = {};
    A.resize(n);
    rep(i,n) cin >> A[i];
    int lef = 0, rig = 2000;
    while(rig - lef > 1){
        int mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}