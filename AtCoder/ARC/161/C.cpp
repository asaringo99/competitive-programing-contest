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
// 1: 黒, 2: 白
vector<int> color;
vector<int> C;
vector<int> use;
vector<int> res;
bool ok;

void dfs(int v, int prev){
    int w = 0, b = 0;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        if(use[u] == 1) b++;
        if(use[u] == 0) w++;
    }
    if(prev == -1){
        if(use[v] == -1) use[v] = 0;
        return;
    }
    if(b == w){
        int val = C[v];
        if(use[prev] == -1) use[prev] = val;
        else{
            if(use[prev] != val) ok = false;
        }
    }
    if(use[v] == -1){
        use[v] = C[prev];
    }
}

void solve(){
    ll n;
    cin >> n;
    string S;
    G = vector<vector<int>>(n);
    color = vector<int>(n,-1);
    use = vector<int>(n,-1);
    res = vector<int>(n,-1);
    int node = 0;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
        if(G[u].size() > 2) node = u;
        if(G[v].size() > 2) node = v;
    }
    C = vector<int>(n,-1);
    cin >> S;
    rep(i,S.size()){
        char u = S[i];
        if(u == 'B') C[i] = 1;
        else C[i] = 0;
    }
    ok = true;
    dfs(node,-1);
    if(!ok){
        cout << -1 << endl;
        return;
    }
    string T = "";
    for(int u : use){
        if(u == 0) T += "W";
        if(u == 1) T += "B";
    }
    rep(i,n){
        int b = 0, w = 0;
        for(int u : G[i]){
            if(T[u] == 'W') w++;
            else b++;
        }
        if(w > b && S[i] == 'W') continue;
        if(b > w && S[i] == 'B') continue;
        cout << -1 << endl;
        return;
    }
    cout << T << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}