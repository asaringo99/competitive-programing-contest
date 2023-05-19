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
    ll a;
    ll b;
};

int n, m, s, t;
ll d[101010][2];
vector<edge> G[101010];

void djikstra(bool flg){
    rep(i,n) d[i][flg] = 1e16 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    if(flg) {
        d[t][1] = 0;
        que.push({0,t,1});
    }
    else{
        d[s][0] = 0;
        que.push({0,s,0});
    }
    while(!que.empty()){
        auto[dist, v, type] = que.top(); que.pop() ;
        if(d[v][type] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            int u = e.to;
            ll cost = flg ? e.b : e.a;
            if(d[u][type] > d[v][type] + cost){
                d[u][type] = d[v][type] + cost;
                que.push({d[u][type],u,type});
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> s >> t;
    s--; t--;
    rep(i,m){
        int u , v , a, b;
        cin >> u >> v >> a >> b;
        u-- ; v-- ;
        G[u].push_back({v,a,b}) ;
        G[v].push_back({u,a,b}) ;
    }
    djikstra(1);
    djikstra(0);
    ll res = 0;
    vector<ll> ans;
    for(int i = n - 1 ; i >= 0 ; i--){
        chmax(res,(ll)1e15 - (d[i][0] + d[i][1]));
        ans.push_back(res);
    }
    for(int i = ans.size() - 1 ; i >= 0 ; i--) cout << ans[i] << endl;
}