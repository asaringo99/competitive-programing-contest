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

vector<vector<int>> G;
vector<vector<P>> dp;
vector<vector<vector<P>>> prevv;
vector<int> res;

P pls(P x, P y) {
    return {x.first + y.first, x.second + y.second};
}

void dfs(int v, int prev){
    dp[v][1].first += 1;
    dp[v][1].second -= (int)G[v].size();
    dp[v][0].second -= 1;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        {
            if(dp[u][0] > dp[u][1]) {
                dp[v][0].first += dp[u][0].first;
                dp[v][0].second += dp[u][0].second;
                prevv[v][0].push_back({u,0});
            }
            else {
                dp[v][0].first += dp[u][1].first;
                dp[v][0].second += dp[u][1].second;
                prevv[v][0].push_back({u,1});
            }
        }
        {
            dp[v][1].first += dp[u][0].first;
            dp[v][1].second += dp[u][0].second;
            prevv[v][1].push_back({u,0});
        }
    }
}

void restore(int v, int k){
    res[v] = 1;
    if(k) res[v] = (int)G[v].size();
    for(P p: prevv[v][k]){
        auto[u,b] = p;
        // cout << v << " " << u << " " << b << endl;
        restore(u,b);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    G = g;
    dp = vector<vector<P>>(n+1,vector<P>(2,{0,0}));
    prevv = vector<vector<vector<P>>>(n+1,vector<vector<P>>(2));
    res = vector<int>(n,0);
    int k = -1;
    rep(i,n) if(G[i].size() > 1) k = i;
    if(k == -1){
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    dfs(k,-1);
    if(dp[k][0] > dp[k][1]){
        cout << dp[k][0].first << " " << -dp[k][0].second << endl;
        restore(k,0);
        rep(i,n) cout << res[i] << " "; cout << endl;
    }
    else{
        cout << dp[k][1].first << " " << -dp[k][1].second << endl;
        restore(k,1);
        rep(i,n) cout << res[i] << " "; cout << endl;
    }
}

int main(){
    fast_io
    solve();
}