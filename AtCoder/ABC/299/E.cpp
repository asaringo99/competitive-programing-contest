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

int n, m, k;
vector<int> G[2020];
bool B[2020];
ll d[2020][2020] ;
ll D[2020];
ll V[2020];
set<int> C[2020];

void djikstra(int q){
    int s = V[q];
    rep(i,n) d[s][i] = 1e16 ;
    d[s][s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        auto[dist, v] = que.top(); que.pop() ;
        if(d[s][v] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[s][u] > d[s][v] + 1){
                d[s][u] = d[s][v] + 1 ;
                que.push(P(d[s][u],u)) ;
            }
        }
    }
    rep(i,n) {
        if(d[s][i] < D[q]) B[i] = false;
        if(d[s][i] == D[q]) C[q].insert(i);
    }
}


int main(){
    fast_io
    cin >> n >> m;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    cin >> k;
    rep(i,k) cin >> V[i] >> D[i], V[i]--;
    rep(i,n) B[i] = true;
    rep(i,k) djikstra(i);
    // rep(i,k){
    //     for(int u : C[i]) cout << u << " "; cout << endl;
    // }
    rep(i,k){
        bool ok = false;
        for(int u : C[i]){
            if(B[u]) ok = true;
        }
        if(!ok){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl ;
    rep(i,n) cout << B[i]; cout << endl;
}