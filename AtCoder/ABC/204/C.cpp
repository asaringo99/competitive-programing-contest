#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m;
vector<int> G[2007] ;
bool d[2007][2007] ;

void dfs(int node , int v){
    d[node][v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!d[node][u]){
            dfs(node,u) ;
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
    }
    ll res = 0 ;
    memset(d,0,sizeof(d)) ;
    for(int i = 0 ; i < n ; i++){
        dfs(i,i) ;
    }
    rep(i,n)rep(j,n) if(d[i][j]) res++ ;
    cout << res << endl ;
}