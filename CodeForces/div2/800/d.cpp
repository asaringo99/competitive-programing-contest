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

vector<vector<int>> G;
vector<ll> R, L, D;
vector<int> dp;

void dfs(int v, int prev){
    ll res = 0, maxval = 0;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        res += dp[u];
        maxval += D[u];
    }
    if(L[v] <= maxval){
        D[v] = min(maxval,R[v]);
    }
    else{
        res++;
        D[v] = R[v];
    }
    dp[v] = res;
}

void solve(){
    int n;
    cin >> n;
    G.clear();
    R.clear();
    L.clear();
    D.clear();
    dp.clear();
    G.resize(n);
    R.resize(n);
    L.resize(n);
    D.resize(n);
    dp.resize(n);
    rrep(i,1,n){
        int v;
        cin >> v;
        v--;
        G[i].push_back(v);
        G[v].push_back(i);
    }
    rep(i,n) cin >> L[i] >> R[i];
    dfs(0,-1);
    cout << dp[0] << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}