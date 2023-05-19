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

struct edge{
    int to ;
    ll cost ;
};

int n , m ;

vector<vector<edge>> G;
vector<ll> d;

void djikstra(int s){
    rep(i,n) d[i] = 1e16 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        auto[dist,v] =  que.top() ; que.pop() ;
        if(d[v] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

void clear(){
    G.clear();
    d.clear();
}

void solve(){
    clear();
    int a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--; b--; c--;
    G.resize(n);
    d.resize(n);
    vector<int> p(n);
    rep(i,m) cin >> p[i];
    rep(i,m){
        ll q = p[i];
        int v, u;
        cin >> v >> u;
        v--; u--;
        G[v].push_back({u,q});
        G[u].push_back({v,q});
    }
    djikstra(b);
    cout << d[a] + d[c] << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}