#include <bits/stdc++.h>
using namespace std ;
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
// build()                     : void                : ビルドを行う
// add_edge(u,v)               : void                : 有向辺 G と逆辺 F を張る
// convert(u)                  : int                 : 元のノード u が新たなグラフでいうどのノードに変異したか
// get_integrated_node_size(u) : int                 : 新たなグラフのノード (0-indexed) には,前のグラフの幾つ分のノードの個数が集約されているか
// get_integrated_node(u)      : vector<int>         : 新たなグラフのノード u に集約された前のグラフのノードリスト
// get_integrated_node()       : vector<vector<int>> : 新たなグラフに集約されたノードリスト
// get_new_gragh_size()        : int                 : 新しく作られたグラフのノード数, 新しいグラフのノード番号は 0-indexed {0,1,2,3,4,..,gragh_size-1}
// get_new_gragh()             : vector<vector<int>> : 新しく作られたグラフ
// *注意* SCCにより生成された新たなグラフは 0-indexedのグラフである
// このままコピペ奨励

int n , m ;

bool ok[202020] , used[202020] ;
vector<vector<int>> G ;

void dfs(int v){
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!used[u]) dfs(u) ;
        if(ok[u]) ok[v] = true ;
    }
}

int main(){
    cin >> n >> m ;
    SCC scc(n) ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        scc.add_edge(a,b) ;
    }
    scc.build() ;
    // SCC後のグラフ ( 0-indexed )
    G = scc.get_new_gragh() ;
    // SCC後に得られたグラフのノード数
    int n_ = scc.get_new_gragh_size() ;

    rep(i,n_){
        if(scc.get_integrated_node_size(i) > 1) ok[i] = true ;
    }
    rep(i,n_){
        if(used[i]) continue;
        dfs(i) ;
    }
    int res = 0 ;
    rep(i,n_){
        if(scc.get_integrated_node_size(i) > 1) res += scc.get_integrated_node_size(i) ;
        else if(ok[i]) res++ ;
    }
    cout << res << endl ;
}