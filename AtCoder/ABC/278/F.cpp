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

int n ;
string T[20];

int dp[1<<20][20];

int rec(int S, int id){
    if(dp[S][id] != -1) return dp[S][id];
    int res = 0;
    int m = T[id].size() - 1;
    rep(i,n){
        if(S >> i & 1) continue;
        if(T[i][0] != T[id][m]) continue;
        int x = rec(S | (1 << i), i);
        if(x == 0) res = 1;
    }
    return dp[S][id] = res;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> T[i];
    rep(S,1<<n) rep(j,n) dp[S][j] = -1;
    bool res = false;
    rep(i,n){
        if(rec(1<<i,i) == 0) res = true;
    }
    if(res) cout << "First" << endl;
    else cout << "Second" << endl;
}