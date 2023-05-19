#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

struct edge
{
    int to ;
    ll cost ;
};

vector<edge> G[2510] , F[2510] ;
bool used1[2510] , used2[2510] , used[2510] ;
ll dist[2510] ;
ll n , m , p ;

void dfs1(int v , int prev){
    used1[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(!used1[e.to]) dfs1(e.to,v) ;
    }
}
void dfs2(int v , int prev){
    used2[v] = true ;
    for(int i = 0 ; i < F[v].size() ; i++){
        edge e = F[v][i] ;
        if(!used2[e.to]) dfs2(e.to,v) ;
    }
}

void init(){
    dfs1(0,-1) ;
    dfs2(n-1,-1) ;
    for(int i = 0 ; i < n ; i++) if(used1[i] && used2[i]) used[i] = true ;
}

bool bfs(){
    fill(dist,dist+2510,1000000000000000) ;
    dist[0] = 0 ;
    int count = 0 ;
    while(true){
        bool update = false ;
        for(int v = 0 ; v < n ; v++){
            if(!used[v] || dist[v] == 1000000000000000) continue ;
            for(int i = 0 ; i < G[v].size() ; i++){
                edge e = G[v][i] ;
                if(dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost ;
                    update = true ;
                }
            }
        }
        count++ ;
        if(!update || count > 2500 + 10) break ;
    }
    if(count < 2500 + 5) return true ;
    else return false ;
}

int main(){
    memset(used1,0,sizeof(used1)) ;
    memset(used2,0,sizeof(used2)) ;
    memset(used,0,sizeof(used)) ;
    cin >> n >> m >> p ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,p-c}) ;
        F[b].push_back(edge{a,p-c}) ;
    }
    init() ;
    bool ok = bfs() ;
    if(ok){
        if(dist[n-1] >= 0) cout << 0 << endl ;
        else cout << -dist[n-1] << endl ;
    }
    else cout << -1 << endl ;
}