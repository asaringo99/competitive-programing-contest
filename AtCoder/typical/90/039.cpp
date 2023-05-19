#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
const int MAX_N = 100007 ;

vector<int> G[MAX_N] ;
ll d[MAX_N] ;
ll to[MAX_N] ;

void dfs(int v , int prev){
    d[v] = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        d[v] += d[u] ;
    }
    to[v] = d[v] * (n - d[v]) ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    memset(to,0,sizeof(to)) ;
    dfs(0,-1) ;
    ll res = 0 ;
    rep(i,n) res += to[i] ;
    cout << res << endl ;
}