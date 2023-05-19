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

vector<vector<int>> G;
bool ok = false;
vector<int> path;

void dfs(int v, int s, int prev){
    path.push_back(v);
    if(v == s){
        ok = true;
        return;
    }
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,s,v);
        if(ok) return;
    }
    path.pop_back();
}

void solve(){
    int n, q;
    cin >> n;
    G.resize(n);
    vector<P> E(n-1);
    vector<vector<int>> ord(n,vector<int>(n,-1));
    vector<vector<int>> val(n,vector<int>(n,1000000));
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        ord[u][v] = i;
        ord[v][u] = i;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
        E[i] = {u,v};
    }
    cin >> q;
    bool p = true;
    rep(i,q){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        path.clear();
        ok = false;
        dfs(a,b,-1);
        int m = path.size();
        rep(j,m-1){
            int v = path[j];
            int u = path[j+1];
            if(val[v][u] < c || val[u][v] < c) p = false;
            if(val[v][u] == 1000000 || val[u][v] == 1000000){
                val[v][u] = c;
                val[u][v] = c;
            }
            else{
                
            }
        }
    }
    if(!p){
        cout << -1 << endl;
        return;
    }
    rep(i,n-1){
        auto[v,u] = E[i];
        cout << val[v][u] << " ";
    }
    cout << endl;
}

int main(){
    fast_input_output
    solve();
}