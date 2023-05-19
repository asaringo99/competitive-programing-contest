#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;

vector<int> G[200007] ;
int d[200007] ;
bool used[200007] ;

void dfs(int v){
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!used[u]){
            d[u] += d[v] ;
            dfs(u) ;
        }
    }
}

int main(){
    memset(d,0,sizeof(d)) ;
    cin >> n >> q ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ; 
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    for(int i = 0 ; i < q ; i++){
        int p , x ;
        cin >> p >> x ;
        p-- ;
        d[p] += x ;
    }
    dfs(0) ;
    rep(i,n) cout << d[i] << " " ;
    cout << endl ;
}