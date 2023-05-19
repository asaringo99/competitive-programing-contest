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

struct edge{
    int to;
    ll cost;
    int id;
};

int n, m, k ;
ll d[202020];
vector<edge> G[202020];
vector<int> F[202020];
TP A[202020];
int E[202020];

void djikstra(vector<int> vec){
    priority_queue<P,vector<P>,greater<P>> que;
    for(int s : vec){
        auto[v,u,c] = A[E[s]];
        d[s] = c;
        que.push({c,s});
    }
    while(!que.empty()){
        auto[dist, id] = que.top(); que.pop();
        if(dist > d[id]) continue;
        int a = E[id];
        auto[v,u,c] = A[a];
        for(edge e: G[u]){
            int nu = e.to;
            int nid = e.id;
            auto it = lower_bound(F[nid].begin(),F[nid].end(),id);
            if(it == F[nid].end()) continue;
            int nx = *it;
            if(d[nx] > d[id] + e.cost){
                d[nx] = d[id] + e.cost;
                que.push({d[nx],nx});
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    rep(i,m){
        int u , v, c ;
        cin >> u >> v >> c ;
        u-- ; v-- ;
        A[i] = {u,v,c};
        G[u].push_back(edge{v,c,i}) ;
    }
    vector<int> vec;
    rep(i,k) {
        cin >> E[i];
        E[i]--;
        F[E[i]].push_back(i);
        auto [v,u,c] = A[E[i]];
        if(v == 0) vec.push_back(i);
    }
    rep(i,k) d[i] = 1e18;
    djikstra(vec);
    ll res = 1e18;
    rep(i,k) {
        auto [v,u,c] = A[E[i]];
        if(u == n - 1) chmin(res,d[i]);
    }
    if(res == 1e18){
        cout << -1 << endl;
    }
    else cout << res << endl;
}