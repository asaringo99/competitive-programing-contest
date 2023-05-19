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

vector<int> G[505050] ;

struct TreeDiameter{
    private :
        const int inf = INT_MAX ;
        int n , diameter ;
        int start_node , end_node , lca ;
        vector<int> dist , parent ;

        void init(){
            dist.resize(n) ;
            parent.resize(n) ;
            dfs(0,-1,0) ;
            int maxval = 0 ;
            start_node = -1 ;
            for(int i = 0 ; i < n ; i++) {
                if(maxval < dist[i]){
                    maxval = dist[i] ;
                    start_node = i ;
                }
                dist[i] = 0 ;
            }
            dfs(start_node,-1,0) ;
            diameter = 0 ;
            end_node = -1 ;
            for(int i = 0 ; i < n ; i++) {
                if(diameter < dist[i]){
                    diameter = dist[i] ;
                    end_node = i ;
                }
            }
            lca = get_lca_() ;
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

        int get_lca_(){
            int v = end_node , res ;
            int count = 0 ;
            while(v != start_node){
                v = parent[v] ;
                count++ ;
                if(count == diameter / 2) res = v ;
            }
            return res ;
        }

        ll rec(int v , int prev , int dep , int value , bool type){
            if(dep == value) return 1 ;
            ll res = (type && v == lca) ? 1 : 0 ;
            ll val = 0 ;
            for(int i = 0 ; i < G[v].size() ; i++){
                int u = G[v][i] ;
                if(u == prev) continue ;
                ll score = rec(u,v,dep+1,value,type) ;
                if(type && v == lca) {
                    (res *= score + 1) %= mod ;
                    (val += score) %= mod ;
                }
                else res += score ;
            }
            return type && v == lca ? (res - val - 1 + mod + mod) % mod : res ;
        }
    
    public :
        TreeDiameter(int n_): n(n_) { init() ; }
        // 木の直径を得る
        int get_diameter() {return diameter ; }
        // 木の直径となる共通祖先のノードを得る
        int get_lca(){ return lca ; }
        // ABC221G
        int get_odd(){ return rec(start_node,-1,0,diameter,false) * rec(end_node,-1,0,diameter,false) % mod ; }
        int get_eve(){ return rec(get_lca(),-1,0,diameter/2,true) ; }
};

int n ;

int main(){
    cin >> n ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    TreeDiameter td(n) ;
    // cout << td.get_diameter() << endl ;
    // cout << td.get_lca() << endl ;
    if(td.get_diameter() & 1) cout << td.get_odd() << endl ;
    else cout << td.get_eve() << endl ;
}