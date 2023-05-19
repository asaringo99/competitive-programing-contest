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

const int mod = 998244353 ;

struct TreeDiameter{
    private :
        vector<vector<int>> G ;
        int n , diameter ;
        // start_node: 直径の端点1, end_node: 直径の端点2, lca: 直径の端点1,2の共通祖先(木の直径の中心)
        int start_node , end_node , lca , lcb;
        vector<int> dist , parent ;

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
    
    public :
        // コンストラクタ
        TreeDiameter(int n_): n(n_) { init_() ; }
        // コンストラクタ
        TreeDiameter() {}
        // 初期化
        void init(int n_) { init_(n_) ; }
        // 辺を張る
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
};

vector<vector<int>> G ;

int dep[202020] ;
int dp[202020] ;
int diameter , lca ;
int lef , rig ;
ll res ;

void dfseven(int v , int prev , int d){
    if(d == diameter / 2) dp[v] = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfseven(u,v,d+1) ;
        dp[v] += dp[u] ;
    }
    if(v == lca){
        ll val = 0 ;
        res = 1 ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            (res *= dp[u] + 1) %= mod ;
            (val += dp[u]) %= mod ;
        }
        (val += 1) %= mod ;
        res = (res - val + mod) % mod ;
    }
}

ll dfsodd(int v , int prev , int d){
    if(d == diameter) return 1 ;
    ll res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        res += dfsodd(u,v,d+1) ;
    }
    return res ;
}

int n ;

int main(){
    cin >> n ;
    TreeDiameter TD(n) ;
    rep(i,n-1){
        int v , u ;
        cin >> u >> v ;
        u-- ; v-- ;
        TD.add_edge(u,v) ;
    }
    TD.build() ;
    diameter = TD.get_diameter() ;
    lca = TD.get_lca() ;
    G = TD.get_graph() ;
    auto [sn,gn] = TD.get_end_node() ;
    if(diameter % 2 == 0){
        dfseven(lca,-1,0) ;
        cout << res << endl ;
    }
    else{
        res = dfsodd(sn,-1,0) * dfsodd(gn,-1,0) % mod ;
        cout << res << endl ;
    }
}