#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

int n , m ;
vector<edge> G[1010] ;
vector<int> F[1010] , H[1010] ;
bool use1[1010] , use2[1010] ;
ll d[1010] ;

void dfs1(int v , int prev){
    use1[v] = true ;
    for(int i = 0 ; i < F[v].size() ; i++){
        int u = F[v][i] ;
        if(u == prev || use1[u]) continue ;
        dfs1(u,v) ;
    }
}

void dfs2(int v , int prev){
    use2[v] = true ;
    for(int i = 0 ; i < H[v].size() ; i++){
        int u = H[v][i] ;
        if(u == prev || use2[u]) continue ;
        dfs2(u,v) ;
    }
}

ll bellmanford(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    int count = 0 ;
    while(count < 1010){
        bool update = true ;
        rep(v,n) if(use1[v] && use2[v]) for(edge e : G[v]) if(use2[e.to] && use2[e.to]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                update = false ;
            }
        }
        if(update) break ;
        count++ ;
    }
    if(count == 1010) return 1e18 ;
    return d[n-1] ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,-c}) ;
        F[a].push_back(b) ;
        H[b].push_back(a) ;
    }
    dfs1(0,-1) ;
    dfs2(n-1,-1) ;
    ll res = bellmanford() ;
    if(res == 1e18) cout << "inf" << endl ;
    else cout << -d[n-1] << endl ;
}