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
#define all(a) a.begin(), a.end()
#define endl "\n"


struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(){}

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

        void init(int n){
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

struct SCC{
    private :
        int n ;
        int gragh_size ;

        // G       : 既存の有向辺についての情報
        // F       : 既存の有向辺（逆辺）についての情報
        // H       : 新たなグラフ（有向辺）の辺についての情報
        // I       : 新たなグラフ（有向辺）の逆辺についての情報
        // used    : dfsで使ったか
        // reused  : Redfsで使ったか
        // conv    : 新たなノードに変換する
        // volume  : 新たなノードに集約されたノード個数
        // cycle   : 新たなノードに集約されたノードがサイクルを持っていたか
        // go      : v -> u に行ったことがあるか
        // restore : 新たなノードに集約された元々のノード一覧

        vector<vector<int>> G , F , H , I;
        vector<int> order ;
        vector<bool> used , reused ;
        vector<int> conv ;
        vector<int> volume ;
        vector<vector<int>> restore ;
        vector<bool> cycle;
        set<P> go ;

        void clear_(){
            n = 0;
            G.clear() ; F.clear() ; H.clear(); I.clear();
            used.clear() ; reused.clear() ;
            conv.clear() ;
            volume.clear() ;
            cycle.clear();
            order.clear();
            restore.clear();
            go.clear();
            gragh_size = 0 ;
        }

        void init_(int n_){
            n = n_ ;
            G.resize(n) ; F.resize(n) ;
            used.resize(n,false) ; reused.resize(n,false) ;
            conv.resize(n) ;
            volume.resize(n,0) ;
            cycle.resize(n,false) ;
            gragh_size = 0 ;
        }


        inline void dfs(int v){
            used[v] = true ;
            for(int i = 0 ; i < G[v].size() ; i++){
                int u = G[v][i] ;
                if(used[u]) continue ;
                dfs(u) ;
            }
            order.push_back(v) ;
        }

        inline void Redfs(int s , int v){
            reused[v] = true ;
            conv[v] = s ;
            volume[s]++ ;
            if(!cycle[s] && volume[s] > 1) cycle[s] = true;
            for(int i = 0 ; i < F[v].size() ; i++){
                int u = F[v][i] ;
                if(u == v) cycle[s] = true;
                if(reused[u]) continue ;
                Redfs(s,u) ;
            }
        }

        void build_(){
            // 処理1 : 1度目のdfs
            for(int i = 0 ; i < n ; i++) if(!used[i]) dfs(i) ;
            // 処理2 : 2度目のdfs
            for(int i = 0 ; i < n ; i++) {
                int v = order[n-1-i] ;
                if(reused[v]) continue ;
                Redfs(gragh_size,v) ;
                gragh_size++ ;
            }
            H.resize(gragh_size) ;
            I.resize(gragh_size) ;
            restore.resize(gragh_size) ;
            // 処理3 : 新しいグラフを作成する
            for(int v = 0 ; v < n ; v++){
                restore[conv[v]].push_back(v) ;
                for(int u : G[v]){
                    int from = conv[v] , to = conv[u] ;
                    if(from == to) continue ;
                    // if(go.count(P(from,to))) continue ;
                    // go.insert(P(from,to));
                    H[from].push_back(to) ;
                    I[to].push_back(from) ;
                }
            }
        }

        inline void add_edge_(int v , int u) {
            G[v].push_back(u) ;
            F[u].push_back(v) ;
        }

    public :
        // n_ : グラフのノード数
        SCC(){}
        SCC(int n_){ init(n_) ; }
        void init(int n_) { init_(n_) ; }
        void clear() { clear_() ; }
        void build() { build_() ; }
        void add_edge(int v , int u) { add_edge_(v,u) ; }
        int convert(int v) { return conv[v] ; } // ノード v は新たなグラフ H 上においてどのノードに変化するか
        bool has_cycle(int v){ return cycle[v] ; }
        int get_integrated_node_size(int v){ return volume[v] ; }
        vector<vector<int>> get_integrated_node() { return restore ; }
        vector<int> get_integrated_node(int v) { return restore[v] ; }
        int get_new_gragh_size(){ return gragh_size ; }
        vector<vector<int>> get_new_gragh() { return H ; }
        int get_new_rev_gragh_size(){ return gragh_size ; }
        vector<vector<int>> get_new_rev_gragh() { return I ; }
} ;

// function                    : return              : description
// -----------------------------------------------------------------
// constructor(int n)          :                     : 元のグラフのサイズが n である構造体を作る
// constructor()               :                     : コンストラクタを行わない場合に利用
// clear                       : void                : メモリを解放する
// init(int n)                 : void                : 元のグラフのサイズが n である構造体を作る
// build()                     : void                : ビルドを行う
// add_edge(u,v)               : void                : 有向辺グラフ G と逆辺グラフ F を張る
// convert(u)                  : int                 : 元のグラフ G のノード u が新たなグラフ H におけるどのノードに変異したか
// has_cycle()                 : vector<int>         : 新たなグラフ H のノード u がサイクルを持っているか
// get_integrated_node_size(u) : int                 : 新たなグラフ H のノード (0-indexed) に元のグラフ G の幾つ分のノードが集約されているか
// get_integrated_node(u)      : vector<int>         : 新たなグラフ H のノード u に集約された元のグラフ G のノードリスト
// get_integrated_node()       : vector<vector<int>> : 新たなグラフ H に集約されたノードリスト
// get_new_gragh_size()        : int                 : 新たなグラフ H のノード数, 新しいグラフのノード番号は 0-indexed {0,1,2,3,4,..,gragh_size-1}
// get_new_gragh()             : vector<vector<int>> : 新たなグラフ H
// get_new_rev_gragh()         : vector<vector<int>> : 新たなグラフ H の逆辺
// ------------------------------------------------------------------
// *注意* SCCにより生成された新たなグラフ H は 0-indexedのグラフである
// このままコピペ奨励

// ------------------------------------------------------- //
// 不安であれば ABC245F sample1, 典型90 021, div3 731G で確認  //
// ------------------------------------------------------- //

struct edge{
    int to;
    ll cost;
};

int n, m, q;
vector<edge> G[101010];
vector<int> F[101010];
vector<vector<int>> H;
bool used[101010];
bool inf_node[101010];
bool inf[101010];
bool done[101010];
set<int> use;

UnionFind uf;
SCC scc;

void dfs(int v, int prev){
    used[v] = true;
    if(scc.has_cycle(v)) inf_node[v] = true;
    for(int u : H[v]){
        if(u == prev) continue;
        if(used[u]) continue;
        used[u] = true;
        if(inf_node[v]) inf_node[u] = true;
        dfs(u,v);
        if(inf_node[u]) inf_node[v] = true;
    }
}

vector<edge> G[202020] ;
ll d[202020] ;

ll rec(int v){
    if(d[v] != -1) return d[v];
    ll res = 1e16;
    for(edge e : G[v]){
        int u = e.to;
        ll cost = e.cost;
        chmin(res,rec(u)-cost);
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> q;
    UnionFind has(n);
    uf.init(n);
    scc.init(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b,c});
        // G[b].push_back({a,0});
        F[a].push_back(b);
        has.unite(a,b);
        scc.add_edge(a,b);
    }
    H = scc.get_new_gragh();
    rep(i,H.size()){
        if(used[i]) continue;
        dfs(i,-1);
        for(int u : scc.get_integrated_node(i)){
            inf[u] = inf_node[i];
        }
    }

    rep(i,q){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(!has.same(x,y)){
            cout << "nan" << endl;
        }
        if(inf[x] || inf[y]){
            cout << "inf" << endl;
        }
        if(!done[has.root(x)]) {
            
        }
    }
}