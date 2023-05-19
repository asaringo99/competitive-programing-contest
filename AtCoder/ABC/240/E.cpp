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

int n ;
vector<int> G[202020] ;
int node[202020] ;
int last[202020] ;

int num = 1 ;
void dfs(int v , int prev){
    if(v != 0 && G[v].size() == 1){
        node[v] = num ;
        last[v] = num ;
        num++ ;
        return ;
    }
    int l = 1e8 , r = -1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        chmin(l,node[u]) ;
        chmax(r,last[u]) ;
    }
    node[v] = l ;
    last[v] = r ;
}

// int dfs2(int v , int prev){
//     int res = node[v] ;
//     for(int i = 0 ; i < G[v].size() ; i++){
//         int u = G[v][i] ;
//         if(u == prev) continue ;
//         chmax(res,dfs2(u,v)) ;
//     }
//     return last[v] = res ;
// }

int main(){
    cin >> n ;
    rep(i,n-1){
        int u  , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1) ;
    rep(i,n){
        cout << node[i] << " " << last[i] << endl ;
    }
}