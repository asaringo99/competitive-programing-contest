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

int n;
vector<int> G[505050];
vector<int> C[505050];
int res[5050];
int D[5050];

void dfs(int v, int prev, int dep){
    D[v] = dep;
    if(!C[dep].empty()){
        int sz = C[dep].size();
        res[v] = C[dep][sz-1];
    }
    C[dep].push_back(v);
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,dep+1);
    }
}

vector<pair<int,int>> vec;
map<int,int> mp;

void ddfs(int v, int prev, int dep){
    if(res[v] == -1){
        // res[v] = vec[vec.size()-1];
        // vec.pop_back();
        vec.push_back({dep,v});
    }
    for(int u: G[v]){
        if(u == prev) continue;
        ddfs(u,v,dep+1);
    }
}

void dddfs(int v, int prev){
    if(res[v] == -1){
        int k = mp[v];
        auto[dd,node] = vec[vec.size()-1-k];
        res[v] = node;
    }
    for(int u: G[v]){
        if(u == prev) continue;
        dddfs(u,v);
    }
}

int main(){
    fast_input_output
    cin >> n;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,n) res[i] = -1;
    dfs(0,-1,0);
    rep(i,n){
        if(res[i] == -1){
            int dep = D[i];
            int sz = C[dep].size();
            if(sz != 1) {
                res[i] = C[dep][sz-1];
            }
        }
    }
    ddfs(0,-1,0);
    sort(all(vec));
    rep(i,vec.size()){
        auto[ddd,v] = vec[i];
        mp[v] = i;
    }

    dddfs(0,-1);
    rep(i,n) cout << res[i] + 1 << " "; cout << endl;
}