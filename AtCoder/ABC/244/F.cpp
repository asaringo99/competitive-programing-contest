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

template<typename T>
struct UnionFind {
    vector<T> par ; //親
    vector<T> lank ; //木の深さ
    vector<T> volume ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        par.resize(n) ;
        lank.resize(n) ;
        volume.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    T root(T x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(T x , T y){
        x = root(x);
        y = root(y) ;
        if(x == y) return ;

        if(lank[x] < lank[y]){
            par[x] = y ;
            volume[y] += volume[x] ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
            volume[x] += volume[y] ;
        }
    }

    bool same(T x , T y){
        return root(x) == root(y) ;
    }

    T size(T x){
        return volume[root(x)] ;
    }
} ;

int n , m ;
ll d[20][20] ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

vector<int> G[20] ;
struct LCA{
    int n ;
    vector<int> dist ;
    vector<vector<int>> parent ;
    LCA(int n_){
        n = n_ ;
        dist.resize(n,-1) ;
        parent.resize(n,vector<int>(30,-1)) ;
        dfs(0,-1,0) ;
        for(int i = 0 ; i < 19 ; i++){
            for(int node = 0 ; node < n ; node++){
                if(parent[node][i] >= 0) parent[node][i+1] = parent[parent[node][i]][i] ;
            }
        }
    }
    //深さ優先探索
    void dfs(int v , int prev , int d){
        dist[v] = d ;
        parent[v][0] = prev ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(dist[u] == -1){
                dfs(u,v,d+1) ;
            }
        }
    }
    //LCAを求める
    int query(int u , int v){
        if(dist[u] < dist[v]) swap(u,v) ;
        for(int i = 0 ; i < 20 ; i++){
            if((dist[v] - dist[u]) >> i & 1) u = parent[u][i] ;
        }
        if(u == v) return u ;
        for(int i = 19 ; i >= 0 ; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i] ;
                v = parent[v][i] ;
            }
        }
        return parent[u][0] ;
    }
    //距離を求める
    int dist_u_to_v(int u , int v){
        int node = query(u,v) ;
        return dist[u] + dist[v] - 2*dist[node] ;
    }
    //u-vパス上に頂点nodeが存在するか
    bool node_is_on_path(int u , int v , int node){
        return dist_u_to_v(u,v) == dist_u_to_v(u,node) + dist_u_to_v(node,v) ;
    }
};

int main(){
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        d[u][v] = 1 ;
        d[v][u] = 1 ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    LCA er(n) ;
    ll res = 0 ;
    rrep(S,1,1<<n){
        int node = -1 ;
        map<int,int> mp ;
        vector<vector<int>> dist(n,vector<int>(n,10000)) ;
        vector<int> vec ;
        rep(i,n) if(S >> i & 1) vec.push_back(i) ;
        int vv = vec.size() ;
        rep(i,vv) rep(j,vv) dist[i][j] = d[i][j] ;
        warshall_floyd() ;
        vector<TP> edge ;
        rep(i,vv) rep(j,vv) if(i != j) edge.push_back({d[i][j],i,j}) ;
        sort(edge.begin(),edge.end()) ;
        UnionFind<ll> uf(n) ;
        for(TP tp : edge){
            auto [cost,u,v] = tp ;
            if(uf.same(u,v)) continue ;
            uf.unite(u,v) ;
            int lca = er.query(u,v) ;
            mp[lca]++ ;
        }
        
    }
}