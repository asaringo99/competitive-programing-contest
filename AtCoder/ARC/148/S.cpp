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

int n, q ;
int A[202020];
vector<int> G[202020];
unordered_set<int> st[202020];
int res[202020];
int mns[202020];

void dfs(int v , int prev){
    // 黒
    for(int u : st[v]){
        if(!st[prev].count(u)) res[u] += G[v].size();
        else res[u] += G[v].size() - 1;
    }
    // 白
    for(int u : st[v]){
        if(st[prev].count(u)) mns[u]++;
    }
    // cout << v << endl;
    // rep(i,n) cout << res[i] << " " ; cout << endl;
    // rep(i,n) cout << mns[i] << " " ; cout << endl; cout << endl;
    for(int u : G[v]){
        if(u == prev) continue;

        dfs(u,v);
    }
}

int main(){
    fast_input_output
    cin >> n >> q ;

    G[1].push_back(0);
    rrep(i,2,n+1){
        int a;
        cin >> a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    rep(i,q){
        int m;
        cin >> m;
        rep(j,m){
            int v;
            cin >> v;
            st[v].insert(i);
        }
    }
    dfs(1,0);
    rep(i,q) cout << res[i] - mns[i] << endl;
}