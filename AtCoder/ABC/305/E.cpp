#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, m, k;
vector<int> G[202020];
int H[202020], P[202020];
int d[202020];

void bfs(){
    priority_queue<pair<int,int>> que;
    rep(i,n){
        if(d[i] == -1) continue;
        que.push({d[i],i});
    }
    while(!que.empty()){
        auto[dist, v] = que.top(); que.pop() ;
        if(d[v] > dist) continue;
        if(d[v] == 0) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] < d[v] - 1){
                d[u] = d[v] - 1 ;
                que.push({d[u],u}) ;
            }
        }
    }
}



void solve(){
    cin >> n >> m >> k;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,k) cin >> P[i] >> H[i], P[i]--;
    rep(i,n) d[i] = -1;
    rep(i,k){
        d[P[i]] = H[i];
    }
    bfs();
    vector<int> vec;
    rep(i,n) if(d[i] >= 0) vec.push_back(i);
    sort(all(vec));
    cout << vec.size() << endl;
    for(int u : vec) cout << u + 1 << " "; cout << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}