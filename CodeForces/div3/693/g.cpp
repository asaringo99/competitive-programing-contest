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
int n, m;
vector<vector<int>> dp;
vector<int> d;
vector<int> dist;
vector<vector<int>> G;

void bfs(vector<vector<int>> G, vector<int> &d){
    rep(i,n) d[i] = 1e8;
    d[0] = 0 ;
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(u) ;
            }
        }
    }
}

int rec(int v, int s){
    if(v == 0) return dp[v][s] = 0;
    if(dp[v][s] != 1e8) return dp[v][s];
    int res = d[v];
    for(int u : G[v]){
        if(d[u] <= d[v]){
            if(s == 0) chmin(res,rec(u,1));
            else chmin(res,d[v]);
        }
        else{
            chmin(res,rec(u,s));
        }
    }
    return dp[v][s] = res;
}

void solve(){
    G.clear();
    dp.clear();
    d.clear();
    dist.clear();
    cin >> n >> m;
    G.resize(n);
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    d.resize(n);
    bfs(G,d);
    dp.resize(n,vector<int>(2,1e8));
    rep(i,n) cout << rec(i,0) << " " ; cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}