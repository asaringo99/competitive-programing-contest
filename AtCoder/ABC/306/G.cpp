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
#define ptv(v) for(auto u : v) cout << u << " "; cout << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

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
        set<pair<int,int>> go ;

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


// void bfs(int root, vector<vector<int>> &G, vector<vector<bool>> &d){
//     int n = G.size();
//     queue<pair<int,int>> que;
//     for(int u : G[root]) {
//         d[u][1] = true, que.push({u,1});
//         cout << u << " ";
//     }
//     cout << endl;
//     while(!que.empty()){
//         auto[v,flg] = que.front(); que.pop();
//         for(int u : G[v]){
//             if(d[u][!flg]) continue;
//             d[u][!flg] = true;
//             que.push({u,!flg});
//         }
//     }
// }

struct TopologicalSort{

    private :
        int n ; // ノード数
        vector<int> order ; // トポロジカルソート後のノードの並び
        vector<int> start ; // 始点ノード
        vector<int> end ; // 終点ノード
        vector<vector<int>> G ;

        vector<int> in ;

        // トポロジカルソートを実施
        void build_(bool inner_sort){
            in.resize(n,0) ;
            for(int i = 0 ; i < n ; i++){
                for(int u : G[i]) in[u]++ ;
            }
            if(inner_sort){
                set<int> st ;
                for(int i = 0 ; i < n ; i++) if(in[i] == 0) {
                    st.insert(i) ;
                    start.push_back(i) ;
                }
                while(!st.empty()){
                    auto it = st.begin() ;
                    int v = *it ; st.erase(it) ;
                    order.push_back(v) ;
                    if(G[v].empty()) end.push_back(v) ;
                    for(int u : G[v]) {
                        in[u]-- ;
                        if(in[u] == 0) st.insert(u) ;
                    }
                }
            }
            else{
                queue<int> que ;
                for(int i = 0 ; i < n ; i++) if(in[i] == 0) {
                    que.push(i) ;
                    start.push_back(i) ;
                }
                while(!que.empty()){
                    int v = que.front() ; que.pop() ;
                    order.push_back(v) ;
                    if(G[v].empty()) end.push_back(v) ;
                    for(int u : G[v]) {
                        in[u]-- ;
                        if(in[u] == 0) que.push(u) ;
                    }
                }
            }
        }

        void add_edge_(int u , int v){
            G[u].push_back(v) ;
        }

        // 閉路判定: true: 閉路あり, false: 閉路なし, O(1)
        bool has_cycle_(){
            int m = order.size() ;
            if(n != m) return true ;
            return false ;
        }

    public :

        // コンストラクタ
        TopologicalSort(int n_){
            n = n_ ;
            G.resize(n) ;
        }

        void build(bool inner_sort = true) { build_(inner_sort) ; }
        void add_edge(int u , int v) { add_edge_(u,v) ; }
        bool has_cycle() { return has_cycle_() ; }
        vector<int> get_start_node() { return start ; }
        vector<int> get_end_node() { return end ; }
        vector<int> sorted() { return order ; }
        vector<vector<int>> get_gragh() { return G ; }
};

// function         : return              : description
// -----------------------------------------------------
// build(bool type) : void                : ビルドする (辺を張った後にビルドすることに注意) type が trueの場合,生成できるトポロジカルソートの中で辞書順最小なものを生成
// add_edge(u,v)    : void                : u -> v に有向辺を張る
// has_cycle()      : bool                : サイクルをもつか
// get_start_node() : vector<int>         : 処理が一番最初に行割れる可能性のあるノードリスト
// get_end_node()   : vector<int>         : 処理が一番最後に行われる可能性のあるノードリスト
// sorted()         : vector<int>         : トポロジカルソートされたノード
// get_gragh()      : vector<vector<int>> : グラフ G を返す
// *注意* 取り敢えず全てをコピペすることを奨励

// ---------------------------------- //
// 不安であれば ABC216D, ABC223D で確認  //
// ---------------------------------- //

set<int> st;

void solve(){
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    vector<tuple<int,int,int>> E;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        scc.add_edge(u,v);
        E.push_back({u,v,i});
    }
    scc.build();
    int root = scc.convert(0);
    auto V = scc.get_integrated_node(root);
    if(V.size() == 1) {
        cout << "No" << endl ;
        return;
    }
    if(st.count(V.size())){
        cout << "Yes" << endl ;
        return;
    }
    set<int> node_list;
    for(int u : V) node_list.insert(u);
    TopologicalSort tps(n);
    for(auto[u,v,id] : E){
        if(node_list.count(u) && node_list.count(v) && v != root){
            tps.add_edge(u,v);
        }
    }
    tps.build();
    auto vec = tps.sorted();
    int sz = vec.size();
    vector<int> to(n);
    rep(i,sz) to[vec[i]] = i;
    auto G = tps.get_gragh();
    rep(i,sz){
        bool odd = false;
        bool eve = false;
        for(int u : G[i]){
            if(to[u] % 2 == 0) eve = true;
            else odd = true;
        }
        if(odd && eve){
            cout << "Yes" << endl ;
            return;
        }
    }
    cout << "No" << endl ;
}

int main(){
    // fast_io
    for(ll x = 1; x * x <= 1000000; x++){
        if(1000000 % x != 0) continue;
        st.insert(x);
        st.insert(1000000/x);
    }
    int t;
    cin >> t;
    rep(i,t) solve();
}