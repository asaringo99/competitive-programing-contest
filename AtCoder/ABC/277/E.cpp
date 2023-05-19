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

int n, m, k ;
vector<pair<int,int>> G[202020];

ll d[202020][2] ;
bool S[202020];

void djikstra(){
    rep(i,n) rep(j,2) d[i][j] = 1e16 ;
    d[0][1] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,1}) ;
    while(!que.empty()){
        auto[dist,v,state] = que.top(); que.pop() ;
        if(d[v][state] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            auto [u,a] = G[v][i] ;
            if(a != state) continue;
            if(d[u][state] > d[v][state] + 1){
                d[u][state] = d[v][state] + 1 ;
                que.push({d[u][state],u,state}) ;
            }
        }
        if(!S[v]) continue;
        state = (state ^ 1);
        if(d[v][state] < dist) continue;;
        d[v][state] = dist;
        for(int i = 0 ; i < G[v].size() ; i++){
            auto [u,a] = G[v][i] ;
            if(a != state) continue;
            if(d[u][state] > d[v][state] + 1){
                d[u][state] = d[v][state] + 1 ;
                que.push({d[u][state],u,state}) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    rep(i,m){
        int u , v, a ;
        cin >> u >> v >> a ;
        u-- ; v-- ;
        G[u].push_back({v,a}) ;
        G[v].push_back({u,a}) ;
    }
    rep(i,k){
        int a;
        cin >> a;
        a--;
        S[a] = true;
    }
    djikstra();
    ll res = min(d[n-1][0], d[n-1][1]);
    if(res == 1e16) res = -1;
    cout << res << endl;
}