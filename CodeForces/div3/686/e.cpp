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

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
};

int z ;
int n;

vector<vector<int>> G;
vector<bool> used;
set<int> S;
bool roop;
ll cnt;

void dfs(int v, int prev){
    if(roop) return;
    if(used[v]) {
        roop = true;
        rrep(i,1,n+1) {
            if(used[i]) {
                S.insert(i);
                cnt++;
            }
        }
        return;
    }
    used[v] = true;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        if(roop) return;
    }
    used[v] = false;
}

int rec(int v, int prev){
    int res = 1;
    // cout << v << " " << prev << endl;
    for(int u : G[v]){
        if(u == prev) continue;
        if(used[u]) continue;
        res += rec(u,v);
    }
    return res;
}

void solve(){
    G.clear();
    used.clear();
    S.clear();
    cin >> n;
    G.resize(n+1);
    used.resize(n+1,false);
    roop = false;
    cnt = 0;
    UnionFind uf(n+1);
    int v = -1;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        if(uf.same(a,b)) v = a;
        uf.unite(a,b);
    }
    dfs(v,-1);
    for(int u : S) {
        G[0].push_back(u);
    }
    ll res = (cnt - 1) * cnt;
    ll s = 0;
    for(int u: G[0]) {
        int k = rec(u,-1) - 1;
        if(k == 0) continue;
        res += (ll)k * (n - k - 1) * 2;
        res += (ll)k * (k + 1) / 2;
        n -= k;
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}