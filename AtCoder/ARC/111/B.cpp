#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N (ll)4e5

int n ;

vector<int> G[MAX_N] ;
bool used[MAX_N] ;
int node_number[MAX_N] ;
int edge[MAX_N] ;
int Size[MAX_N] ;

void bfs(int n){
    memset(Size,0,sizeof(Size)) ;
    for(int i = 0 ; i < n ; i++){
        queue<int> que ;
        que.push(i) ;
        int num = 0 ;
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            if(used[v]) continue ;
            num++ ;
            used[v] = true ;
            node_number[v] = i ;
            for(int j = 0 ; j < G[v].size() ; j++){
                int u = G[v][j] ;
                if(used[u]) continue ;
                que.push(u) ;
            }
        }
        Size[i] = num ;
    }
}

void how_edge(int n){
    memset(edge,0,sizeof(edge)) ;
    for(int i = 0 ; i < n ; i++){
        int flag = node_number[i] ;
        int edge_num = G[i].size() ;
        edge[flag] += edge_num ;
    }
    for(int i = 0 ; i < n ; i++){
        edge[i] /= 2 ;
    }
}


int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    bfs(MAX_N) ;
    how_edge(MAX_N) ;
    ll ans = 0 ;
    for(int i = 0 ; i < MAX_N ; i++){
        if(Size[i] - 1 == edge[i]) ans += Size[i] - 1 ;
        else ans += Size[i] ;
    }
    cout << ans << endl ;
}