#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

vector<vector<int>> G;
vector<ll> dp;
vector<ll> dep;
vector<ll> d;
ll n, k, c;

void dfs(int v, int prev, int depth){
    dep[v] = depth;
    ll res = 0;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,depth+1);
        chmax(res,d[u]);
    }
    chmax(res,dep[v]*k);
    d[v] = res;
}

void rec(int v, int prev, ll cost){
    if(v == 0){
        dp[v] = d[v];
        pair<ll,int> d1 = {0,-1};
        pair<ll,int> d2 = {0,-1};
        for(int u : G[v]){
            if(u == prev) continue;
            if(d[u] > d2.first) d2 = {d[u],u};
            if(d2> d1) swap(d1, d2);
        }
        for(int u : G[v]){
            if(u == prev) continue;
            ll val = d1.first;
            if(u == d1.second) val = d2.first;
            chmax(val,cost);
            val += k;
            rec(u,v,val);
        }
        return;
    }
    dp[v] = max(cost,d[v]-dep[v]*k);
    pair<ll,int> d1 = {0,-1};
    pair<ll,int> d2 = {0,-1};
    for(int u : G[v]){
        if(u == prev) continue;
        if(d[u] > d2.first) d2 = {d[u]-dep[v]*k,u};
        if(d2> d1) swap(d1, d2);
    }
    for(int u : G[v]){
        if(u == prev) continue;
        ll val = d1.first;
        if(u == d1.second) val = d2.first;
        chmax(val,cost);
        val += k;
        rec(u,v,val);
    }
}

void solve(){
    cin >> n >> k >> c;
    G = vector<vector<int>>(n);
    dp = vector<ll>(n,1e18);
    d = vector<ll>(n,0);
    dep = vector<ll>(n,0);
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1,0);
    rec(0,-1,0);
    ll res = -1e18;
    rep(i,n){
        chmax(res,dp[i] - dep[i] * c);
    }
    // rep(i,n) cout << dp[i] << " "; cout << endl;
    cout << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}