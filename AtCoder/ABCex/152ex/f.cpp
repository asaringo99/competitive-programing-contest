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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int n , m ;
vector<int> G[101] ;
ll d[101] ;

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

int pre[101] ;
void dfs(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        pre[u] = v ;
        dfs(u,v) ;
    }
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a, b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    LCA lca(n) ;
    dfs(0,-1) ;
    cin >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        int nod = lca.query(u,v) ;
        ll val = 0 ;
        int x = u ;
        while(x != nod){
            val |= 1LL << x ;
            x = pre[x] ;
        }
        int y = v ;
        while(y != nod){
            val |= 1LL << y ;
            y = pre[y] ;
        }
        d[i] = val ;
    }
    ll res = 0 ;
    rrep(S,1,1<<m){
        ll val = 0 ;
        rep(i,m) if(S >> i & 1) val |= d[i] ;
        if(bit_count(S) % 2 == 1) res += powll(2,n-1-bit_count(val)) ;
        if(bit_count(S) % 2 == 0) res -= powll(2,n-1-bit_count(val)) ;
    }
    cout << powll(2,n-1) - res << endl ;
}