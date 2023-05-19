#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
vector<int> G[100007] ;
bool visited[100007] ;

void dfs(int v , int& cnt){
    visited[v] = true ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(v > u) res++ ;
        if(visited[u]) continue ;
        dfs(u,cnt) ;
    }
    if(res == 1) cnt++ ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    int cnt = 0 ;
    dfs(0,cnt) ;
    cout << cnt << endl ;
}