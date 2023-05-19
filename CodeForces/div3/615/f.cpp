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

struct TreeDiameter{
    private :
        vector<vector<int>> G ;
        int n , diameter ;
        // start_node: 直径の端点1, end_node: 直径の端点2, lca: 直径の端点1,2の共通祖先(木の直径の中心)
        int start_node , end_node , lca , lcb;
        vector<int> dist , parent, path ;

        void init_() {
            dist.resize(n) ;
            parent.resize(n) ;
            G.resize(n) ;
        }

        void init_(int n_) {
            n = n_ ;
            dist.resize(n) ;
            parent.resize(n) ;
            G.resize(n) ;
        }

        void add_edge_(int v , int u){
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }

        void build_() {
            dfs(0,-1,0) ;
            int maxval = -1 ;
            start_node = -1 ;
            for(int i = 0 ; i < n ; i++) {
                if(maxval < dist[i]){
                    maxval = dist[i] ;
                    start_node = i ;
                }
                dist[i] = 0 ;
            }
            dfs(start_node,-1,0) ;
            diameter = -1 ;
            end_node = -1 ;
            for(int i = 0 ; i < n ; i++) {
                if(diameter < dist[i]){
                    diameter = dist[i] ;
                    end_node = i ;
                }
            }
            get_lca_() ;
            bool ok = false;
            get_diameter_path_(start_node, end_node, -1, ok);
        }

        void dfs(int v , int prev , int dep){
            dist[v] = dep ;
            parent[v] = prev ;
            for(int i = 0 ; i < G[v].size() ; i++){
                int u = G[v][i] ;
                if(u == prev) continue ;
                dfs(u,v,dep+1) ;
            }
        }

        void get_lca_(){
            int v = end_node;
            int count = 0 ;
            while(v != -1){
                if(count == diameter / 2) lca = v ;
                if(count == (diameter + 1) / 2) lcb = v ;
                v = parent[v] ;
                count++ ;
            }
        }

        void get_diameter_path_(int v, int s, int prev, bool &ok){
            path.push_back(v);
            if(v == s){
                ok = true;
                return;
            }
            for(int u : G[v]){
                if(u == prev) continue;
                get_diameter_path_(u,s,v,ok);
                if(ok) return;
            }
            path.pop_back();
        }
    
    public :
        // コンストラクタ
        TreeDiameter(int n_): n(n_) { init_() ; }
        // コンストラクタ
        TreeDiameter() {}
        // 初期化
        void init(int n_) { init_(n_) ; }
        // 辺を張る(両辺から)
        void add_edge(int v , int u) { add_edge_(v,u) ; }
        // ビルドする
        void build() { build_() ; }
        // グラフを得る
        vector<vector<int>> get_graph() { return G ; }
        // 木の直径を取得
        int get_diameter() {return diameter ; }
        // 木の直径を生成する共通祖先のノードを取得(木の中心を取得)
        int get_lca(){ return lca ; }
        int get_lcb(){ return lcb ; }
        // 木の直径を生成する2つのノード
        P get_end_node() { return P(start_node,end_node) ; }
        // 直径を構成するノード集合
        vector<int> get_diameter_path() { return path; }
};

vector<vector<int>> G;
bool C[202020];

pair<int,int> dfs(int v, int prev, int dep){
    int res = dep, ver = v;
    for(int u: G[v]){
        if(u == prev) continue;
        if(C[u]) continue;
        auto[d,node] = dfs(u,v,dep+1);
        if(d > res){
            res = d;
            ver = node;
        }
    }
    return {res, ver};
}

void solve(){
    int n;
    cin >> n;
    TreeDiameter tree(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree.add_edge(a,b);
    }
    tree.build();
    vector<int> path = tree.get_diameter_path();
    for(int u : path) C[u] = true;
    G = tree.get_graph();
    int res = 0, node = path[path.size()/2];
    for(int u : path){
        auto[d,ver] = dfs(u,-1,0);
        if(d > res){
            res = d;
            node = ver;
        }
    }
    cout << res + path.size() - 1 << endl;
    cout << path[0] + 1 << " " << path[path.size()-1] + 1 << " " << node + 1 << endl;
}

int main(){
    fast_input_output
    solve();
}