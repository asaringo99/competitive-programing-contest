#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

struct SCC{
    private :
        int n ;
        int gragh_size ;

        // G       : 既存の有向辺についての情報
        // F       : 既存の有向辺（逆辺）についての情報
        // H       : 新たなグラフ（有向辺）の辺についての情報
        // used    : dfsで使ったか
        // reused  : Redfsで使ったか
        // conv    : 新たなノードに変換する
        // volume  : 新たなノードに集約されたノード個数
        // go      : v -> u に行ったことがあるか
        // restore : 新たなノードに集約された元々のノード一覧

        vector<vector<int>> G , F , H ;
        vector<int> order ;
        vector<bool> used , reused ;
        vector<int> conv ;
        vector<int> volume ;
        vector<vector<int>> restore ;
        map<P,bool> go ;

        void init_(int n_){
            n = n_ ;
            G.resize(n) ; F.resize(n) ;
            used.resize(n,false) ; reused.resize(n,false) ;
            conv.resize(n) ;
            volume.resize(n) ;
            gragh_size = 0 ;
        }

        void dfs(int v){
            used[v] = true ;
            for(int i = 0 ; i < G[v].size() ; i++){
                int u = G[v][i] ;
                if(used[u]) continue ;
                dfs(u) ;
            }
            order.push_back(v) ;
        }

        void Redfs(int s , int v){
            reused[v] = true ;
            conv[v] = s ;
            volume[s]++ ;
            for(int i = 0 ; i < F[v].size() ; i++){
                int u = F[v][i] ;
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
            restore.resize(gragh_size) ;
            // 処理3 : 新しいグラフを作成する
            for(int v = 0 ; v < n ; v++){
                restore[conv[v]].push_back(v) ;
                for(int u : G[v]){
                    int from = conv[v] , to = conv[u] ;
                    if(from == to) continue ;
                    if(go[P(from,to)]) continue ;
                    go[P(from,to)] = true ;
                    H[from].push_back(to) ;
                }
            }
        }

        inline void add_edge_(int v , int u) {
            G[v].push_back(u) ;
            F[u].push_back(v) ;
        }

    public :
        // n_ : グラフのノード数
        SCC(int n_){
            n = n_ ;
            G.resize(n) ; F.resize(n) ;
            used.resize(n,false) ; reused.resize(n,false) ;
            conv.resize(n) ;
            volume.resize(n) ;
            gragh_size = 0 ;
        }
        SCC(){}
        void init(int n_) { init_(n_) ; }
        void build() { build_() ; }
        void add_edge(int v , int u) { add_edge_(v,u) ; }
        int convert(int v) { return conv[v] ; } // ノード v は新たなグラフ H 上においてどのノードに変化するか
        int get_integrated_node_size(int v){ return volume[v] ; }
        vector<vector<int>> get_integrated_node() { return restore ; }
        vector<int> get_integrated_node(int v) { return restore[v] ; }
        int get_new_gragh_size(){ return gragh_size ; }
        vector<vector<int>> get_new_gragh() { return H ; }
} ;

// function                    : return              : description
// -----------------------------------------------------------------
// constructor(int n)          :                     : 元のグラフのサイズが n である構造体を作る
// constructor()               :                     : コンストラクタを行わない場合に利用
// init(int n)                 : void                : 元のグラフのサイズが n である構造体を作る
// build()                     : void                : ビルドを行う
// add_edge(u,v)               : void                : 有向辺グラフ G と逆辺グラフ F を張る
// convert(u)                  : int                 : 元のグラフ G のノード u が新たなグラフ H におけるどのノードに変異したか
// get_integrated_node_size(u) : int                 : 新たなグラフ H のノード (0-indexed) に元のグラフ G の幾つ分のノードが集約されているか
// get_integrated_node(u)      : vector<int>         : 新たなグラフ H のノード u に集約された元のグラフ G のノードリスト
// get_integrated_node()       : vector<vector<int>> : 新たなグラフ H に集約されたノードリスト
// get_new_gragh_size()        : int                 : 新たなグラフ H のノード数, 新しいグラフのノード番号は 0-indexed {0,1,2,3,4,..,gragh_size-1}
// get_new_gragh()             : vector<vector<int>> : 新たなグラフ H
// ------------------------------------------------------------------
// *注意* SCCにより生成された新たなグラフ H は 0-indexedのグラフである
// このままコピペ奨励

// -------------------------------------------- //
// 不安であれば ABC245F sample1, 典型90 021 で確認  //
// -------------------------------------------- //

int n , m ;
vector<vector<int>> G , F ; // 新たなグラフ
SCC scc ;
ll B[101010] , C[101010] , D[101010] , E[101010] ;
bool used[101010] ;

bool bfs(int s){
    bool ok = true ;
    int x = 1 ;
    queue<int> que ;
    que.push(s) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        if(used[v]){
            if(x == 0) ok = false ;
            break ;
        }
        used[v] = true ;
        if(C[v] < D[v]) x ^= 1 ;
        for(int u : F[v]){
            que.push(u) ;
        }
    }
    return ok ;
}

int main(){
    cin >> n ;
    scc.init(n) ;
    F.resize(n) ;
    rep(i,n){
        int a , b ;
        cin >> a >> b >> C[i] >> D[i] ;
        E[i] = b;
        a-- ;
        B[a] += b ;
        scc.add_edge(i,a) ;
        F[i].push_back(a) ;
    }
    scc.build() ;
    // SCC後のグラフ ( 0-indexed )
    G = scc.get_new_gragh() ;
    // SCC後に得られたグラフのノード数
    int N = scc.get_new_gragh_size() ;
    ll res = 0 ;
    rep(i,N){
        vector<int> vec = scc.get_integrated_node(i) ;
        if(vec.size() <= 1) {
            int v = vec[0] ;
            res += B[v] * max(C[v],D[v]) ;
        }
        else{
            ll val = 0 , tmp = 0 , minval = 1e18 ;
            for(int u : vec){
                B[F[u][0]] -= E[u] ;
            }
            for(int u : vec){
                val += max(C[u],D[u]) * B[u] ;
            }
            for(int u : vec){
                B[F[u][0]] = E[u] ;
            }
            for(int u : vec){
                val += max(C[u],D[u]) * B[u] ;
                chmin(minval,abs(D[u]-C[u])*B[u]) ;
            }
            if(bfs(vec[0])) res += val ;
            else res += val - minval ;
        }
    }
    cout << res << endl ;
}