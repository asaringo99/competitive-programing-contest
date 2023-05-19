#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

int n , m ;

vector<edge> G[202020] ;
ll d[202020] ;
set<int> st ;
bool ok = true ;

void dfs(int v){
    rep(i,G[v].size()){
        edge e = G[v][i] ;
        int u = e.to ;
        if(d[u] != -1e16){
            if(d[v] + e.cost != d[u]) ok = false ;
            continue ;
        }
        d[u] = d[v] + e.cost ;
        dfs(u) ;
    }
}

int main(){
    cin >> n >> m ;
    int s = -1 ;
    rep(i,m){
        int v , u , c ;
        cin >> v >> u >> c ;
        v-- ; u-- ;
        if(i == 0) s = v ;
        d[v] = -1e16 ;
        d[u] = -1e16 ;
        st.insert(v) ;
        st.insert(u) ;
        G[v].push_back(edge{u,c}) ;
        G[u].push_back(edge{v,-c}) ;
    }
    for(int u : st){
        if(d[u] == -1e16){
            d[u] = 0 ;
            dfs(u) ;
        }
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}