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

int n, m , k ;
vector<int> G[101010];
int A[202020], B[202020];
set<int> C[202020];
int d[202020];

void bfs(){
    rep(i,n) d[i] = k + 1;
    priority_queue<P,vector<P>,greater<P>> que;
    if(A[0] == B[0]) {
        d[0] = 1;
        que.push({1,0});
    }
    else {
        d[0] = 0;
        que.push({0,0});
    }
    while(!que.empty()){
        auto[dist,v] = que.top(); que.pop();
        if(dist > d[v]) continue;
        int nv;
        if(dist == k) nv = k;
        else nv = B[dist];
        for(int u : G[v]){
            if(d[u] <= d[v]) continue;
            if(C[nv].count(u)) {
                if(d[u] > d[v] + 1){
                    d[u] = d[v] + 1;
                    que.push({d[u],u});
                }
            }
            else{
                if(d[u] > d[v]){
                    d[u] = d[v];
                    que.push({d[u],u});
                }
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,n) {
        cin >> A[i];
        A[i]--;
        C[A[i]].insert(i);
    }
    rep(i,k) cin >> B[i], B[i]--;
    bfs();
    if(d[n-1] == k){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl; 
}