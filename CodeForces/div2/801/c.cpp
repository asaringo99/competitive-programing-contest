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

void solve(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    vector<vector<int>> dp1(H,vector<int>(W,1e8));
    vector<vector<int>> dp2(H,vector<int>(W,-1e8));
    rep(i,H) rep(j,W) cin >> A[i][j];
    if((H + W) % 2 == 0){
        cout << "NO" << endl;
        return;
    }
    dp1[0][0] = A[0][0];
    dp2[0][0] = A[0][0];
    rep(i,H) rep(j,W){
        if(i + 1 < H) chmin(dp1[i+1][j], dp1[i][j] + A[i+1][j]);
        if(i + 1 < H) chmax(dp2[i+1][j], dp2[i][j] + A[i+1][j]);
        if(j + 1 < W) chmin(dp1[i][j+1], dp1[i][j] + A[i][j+1]);
        if(j + 1 < W) chmax(dp2[i][j+1], dp2[i][j] + A[i][j+1]);
    }
    if(dp1[H-1][W-1] <= 0 && dp2[H-1][W-1] >= 0){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}