#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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
// get_start_node() : vector<int>         : 処理が一番最初に行割れる可能性のあるノードリスト
// get_end_node()   : vector<int>         : 処理が一番最後に行われる可能性のあるノードリスト
// sorted()         : vector<int>         : トポロジカルソートされたノード
// get_gragh()      : vector<vector<int>> : グラフ G を返す

int n , H , W ;
int C[101][101] ;
int X[1010][4] ;

int main(){
    cin >> n >> H >> W ;
    TopologicalSort ts(n) ;
    rep(i,n+1){
        X[i][0] = 1e9 ;
        X[i][1] = 1e9 ;
        X[i][2] = 0 ;
        X[i][3] = 0 ;
    }
    rep(i,H) rep(j,W) {
        int c ;
        cin >> c ;
        c-- ;
        C[i][j] = c ;
        if(c == -1) continue;
        chmin(X[c][0],i) ;
        chmax(X[c][2],i) ;
        chmin(X[c][1],j) ;
        chmax(X[c][3],j) ;
    }
    rep(i,n){
        int sx = X[i][0] , gx = X[i][2] ;
        int sy = X[i][1] , gy = X[i][3] ;
        set<int> st ;
        rrep(x,sx,gx+1) rrep(y,sy,gy+1) {
            if(C[x][y] != i) st.insert(C[x][y]) ;
        }
        for(int u : st) ts.add_edge(i,u) ;
    }
    ts.build() ;
    vector<int> res = ts.sorted() ;
    rep(i,n){
        int ans = res[i] + 1 ;
        if(i == n - 1) cout << ans << endl ;
        else cout << ans << " " ;
    }
}