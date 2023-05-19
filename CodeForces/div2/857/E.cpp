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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

vector<int> G[21];

int n , m ;

ll d[21] ;

void djikstra(int s){
    rep(i,n) d[i] = 1e16 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        auto[dist, v] = que.top(); que.pop() ;
        if(d[v] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}

vector<bool> used;
int res[30];

void dfs(int v, int prev){
    if(used[v]) return;
    used[v] = true;
    for(int u: G[v]){
        if(u == prev) continue;
        if(used[u]) continue;
        res[u] = v;
        dfs(u,v);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    vector<ll> F(n,1e8);
    ll minval = 1e9;
    int s = -1;
    rep(i,n){
        djikstra(i);
        rep(j,n) {
            if(d[j] > 3){
                cout << "NO" << endl;
                return;
            }
            chmin(F[i],d[j]);
        }
        if(F[i] < minval){
            minval = F[i];
            s = i;
        }
    }
    used.resize(n,false);
    dfs(s,-1);
    ll maxval = 0;
    int t = -1;
    for(int u : G[s]){
        if(maxval < F[u]){
            maxval = F[u];
            t = u;
        }
    }
    res[s] = t;
    cout << "YES" << endl;
    rep(i,n) cout << res[i] << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}