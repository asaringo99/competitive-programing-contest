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

template<typename T=ll> struct UnionFind {
    private:
        vector<int> parent ; //親
        vector<int> rank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数
        vector<T> weight ; //親の重みとの差(親の重みは0)
        vector<bool> paradox;

    public:
        UnionFind(int n){
            //n要素で初期化
            parent.resize(n) ;
            rank.resize(n,0) ;
            volume.resize(n,1) ;
            edge.resize(n,0) ;
            weight.resize(n,0) ;
            paradox.resize(n,false);
            for(int i = 0 ; i < n ; i++) parent[i] = i ;
        }

        T potential(int x){
            root(x);
            return weight[x];
        }

        //木の根を求める
        int root(int x) {
            if(parent[x] == x) return x;
            int r = root(parent[x]);
            weight[x] += weight[parent[x]];
            return parent[x] = r;
        }

        //xとyの属する集合を合併
        void unite(int x, int y, T w = 0){
            w += potential(x) - potential(y);

            x = root(x);
            y = root(y);
            if(x == y) {
                if(w != 0) paradox[x] = true;
                edge[x]++ ;
                return ;
            }
            if(rank[x] < rank[y]){
                swap(x,y);
                w = -w;
            } 
            if(rank[x] == rank[y]) rank[x]++;
            if(paradox[y]) paradox[x] = true;
            parent[y] = x;
            volume[x] += volume[y];
            edge[x] += edge[y] + 1;
            weight[y] = w;
        }

        bool same(int x , int y) { return root(x) == root(y); }
        int size(int x) { return volume[root(x)]; }
        int edge_num(int x) { return edge[root(x)]; }
        T diff(int x, int y){ return potential(y) - potential(x); }
        bool conflict(int x) { return paradox[root(x)]; }
};

int n, m, k;
pair<int,int> E[202020];
bool B[202020];
int X[202020];

int main(){
    fast_io
    cin >> n >> m;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        E[i] = {u,v};
    }
    cin >> k;
    rep(i,k){
        int x;
        cin >> x;
        x--;
        B[x] = true;
        X[i] = x;
    }
    UnionFind uf(n);
    rep(i,m){
        auto[u,v] = E[i];
        if(!B[i]) uf.unite(u,v);
    }
    vector<vector<int>> G(n);
    rep(i,k){
        auto[u,v] = E[X[i]];
        if(uf.same(u,v)) continue;
        u = uf.root(u);
        v = uf.root(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int odd = 0;
    rep(i,n){
        if(G[i].size() % 2 != 0) odd++;
    }
    if(odd == 2 || odd == 0) pt("Yes");
    else pt("No");
}