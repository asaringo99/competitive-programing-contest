#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
int par[101010] ;

vector<int> G[101010] ;

void dfs(int v , int prev){
    int res = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        res += par[u] ;
    }
    par[v] = res ;
}

int main(){
    cin >> n >> q ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    ll sum = 0 ;
    rep(i,q){
        ll p , x ;
        cin >> p >> x ;
        p-- ;
        sum += x * par[p] ;
        cout << sum << endl ;
    }
}