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

int n;
string S[101010], T[101010];
set<string> st;
map<string,int> mp;

int main(){
    fast_io
    cin >> n;
    rep(i,n) cin >> S[i] >> T[i];
    int cnt = 0;
    rep(i,n){
        if(!mp.count(S[i])) mp[S[i]] = cnt++;
    }
    rep(i,n){
        if(!mp.count(T[i])) mp[T[i]] = cnt++;
    }

    TopologicalSort tps(cnt);

    rep(i,n){
        int a = mp[S[i]], b = mp[T[i]];
        // cout << a << " " << b << endl;
        tps.add_edge(a,b);
    }
    tps.build();
    if(tps.has_cycle()) pt("No");
    else pt("Yes");
}