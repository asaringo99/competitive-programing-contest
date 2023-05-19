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

struct edge{
    int from;
    int to;
    int id;
};

template<typename Edge = edge> struct DfsTree{
    private:
        int n;
        vector<int> ord;
        vector<int> low;
        vector<vector<Edge>> G;
        vector<vector<Edge>> back_edge; // 後退辺
        vector<int> topological_sort;
        vector<Edge> bridge; // 橋
        vector<int> aps; // 関節点
        vector<vector<int>> tecc; // 連結成分iが含んでいるノードリスト
        vector<int> tecc_idx; // ノードの連結成分番号
        vector<vector<int>> tecc_tree; // 連結成分を頂点、橋を辺としたグラフ(木)の隣接リスト

        void init_(int n_){
            n = n_;
            ord.resize(n,-1);
            low.resize(n,n);
            G.resize(n);
            back_edge.resize(n);
            tecc_idx.resize(n,-1);
        }

        // 有向辺を張る
        void add_edge_(int u, Edge v){
            G[u].push_back(v);
        }

        void build_(){
            low_link();
            two_edge_connected_component();
        }

        void low_link(){
            int current = 0;
            for(int i = 0; i < n; i++) if(ord[i] == -1) dfs_bridge(i,-1,current);
        }

        void dfs_bridge(int v, int prev_id, int &current){
            bool is_root = prev_id == -1 ? true : false;
            bool is_aps = false;
            ord[v] = current++;
            int count = 0;
            topological_sort.push_back(v);
            for(Edge e : G[v]){
                auto[from, u, id] = e;
                if(id == prev_id) continue;
                if(ord[u] != -1) {
                    count++;
                    low[v] = min(low[v],ord[u]);
                    back_edge[v].push_back(e);
                    continue;
                }
                dfs_bridge(u,id,current);
                low[v] = min(low[v], low[u]);
                if(!is_root && ord[v] <= low[u]) is_aps = true;
                if(ord[v] < low[u]) bridge.emplace_back(e);
            }
            if(is_root && count >= 2) is_aps = true;
            if(is_aps) aps.push_back(v);
        }

        void two_edge_connected_component(){
            int id = 0;
            int bridge_size = (int)bridge.size();
            tecc_tree.resize(n);
            for(int i = 0; i < n; i++) {
                if(tecc_idx[i] != -1) continue;
                tecc.push_back({});
                dfs(i,-1,(int)tecc.size()-1);
            }
        }

        void dfs(int v, int prev, int id){
            tecc_idx[v] = id;
            tecc[id].push_back(v);
            for(edge e : G[v]){
                int u = e.to;
                if(u == prev) continue;
                // すでに訪れているか
                if(tecc_idx[u] != -1) continue;
                // 橋であるか
                if(low[u] > ord[v] || low[v] > ord[u]) {
                    tecc.push_back({});
                    dfs(u,v,(int)tecc.size()-1);
                    tecc_tree[id].push_back(tecc_idx[u]);
                    tecc_tree[tecc_idx[u]].push_back(id);
                }
                else dfs(u,v,id);
            }
        }

    public:
        DfsTree(){}
        DfsTree(int n) { init_(n); }
        void init(int n) { init_(n); }
        void add_edge(int u, Edge v){ add_edge_(u, v); }
        void build() { build_(); }
        vector<Edge> get_bridge() { return bridge; } // 橋を取得
        vector<int> get_aps() { return aps; } // 関節点を取得
        vector<vector<int>> get_graph() { return G; } // グラフの取得
        vector<vector<Edge>> get_back_edge() { return back_edge; } // 後退辺の取得
        vector<vector<int>> get_all_two_edge_connected_compoonent() { return tecc; }
        vector<int> get_two_edge_connected_compoonent(int k) { return tecc[k]; } // 集約したグラフのノードkに含まれている元々の頂点集合
        int root(int v) { return tecc_idx[v]; } // 元々のノードが集約されたあとどのノードになったか
        vector<vector<int>> get_tecc_tree() { return tecc_tree; } // 元々のグラフを集約して得られた新しいグラフ
};

vector<tuple<int,int,int>> E[1010101];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> X;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        E[c].push_back({a,b,i});
        X.push_back({c,a,b});
    }
    UnionFind uf(n);
    DfsTree dfstree(n);
    vector<int> res(m,0);
    rep(i,1010101){
        unordered_map<int,int> mp;
        int c = 0;
        for(auto[v,u,id] : E[i]){
            if(uf.same(v,u)){
                res[id] = -1;
                continue;
            }
            v = uf.root(v);
            u = uf.root(u);
            if(mp.count(v) == 0) mp[v] = c++;
            if(mp.count(u) == 0) mp[u] = c++;
        }
        DfsTree dfstree((int)E[i].size()*3);
        for(auto[vv,uu,id] : E[i]){
            if(res[id] == -1) continue;
            int v = uf.root(vv);
            int u = uf.root(uu);
            dfstree.add_edge(mp[u], {mp[u], mp[v], id});
            dfstree.add_edge(mp[v], {mp[v], mp[u], id});
        }
        for(auto[vv,uu,id] : E[i]){
            if(res[id] == -1) continue;
            uf.unite(uu,vv);
        }
        dfstree.build();
        for(auto edge : dfstree.get_bridge()){
            res[edge.id] = 1;
        }
    }
    rep(i,m){
        if(res[i] == -1) cout << "none" << endl;
        if(res[i] == 0) cout << "at least one" << endl;
        if(res[i] == 1) cout << "any" << endl;
    }
}

int main(){
    fast_io
    solve();
}