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

int d[505050];

set<int> D;

void dfs(int v, int prev, int dep){
    bool ok = true;
    for(int u : G[v]){
        if(u == prev) continue;
        ok = false;
        dfs(u,v,dep+1);
    }
    if(ok) {
        D.insert(dep);
        d[dep]++;
    }
}

void solve(){
    ll n;
    cin >> n;
    G = vector<vector<int>>(n);
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    int res = 0;
    for(int u : G[0]){
        dfs(u,0,1);
        int s = 0;
        for(int i : D){
            if(s < i) s = i + d[i] - 1;
            else s += d[i];
        }
        for(int i : D) d[i] = 0;
        chmax(res,s);
        D = {};
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}