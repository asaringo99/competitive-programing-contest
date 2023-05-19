#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int to ;
    ll cost ;
};


int n , x ;
int d[101010] ;
unordered_map<ll,ll> S ;

vector<edge> G[101010] ;

void dfs(int v , int prev){
    S[d[v]]++ ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(e.to == prev) continue ;
        d[e.to] = d[v] ^ e.cost ;
        dfs(e.to,v) ;
    }
}

int main(){
    cin >> n >> x ;
    rep(i,n-1){
        int x , y , z ;
        cin >> x >> y >> z ;
        x-- ; y-- ;
        G[x].push_back(edge{y,z}) ;
        G[y].push_back(edge{x,z}) ;
    }
    dfs(0,-1) ;
    ll res = 0 ;
    rep(i,n){
        S[d[i]]-- ;
        res += S[d[i] ^ x] ;
        S[d[i]]++ ;
    }
    cout << res / 2 << endl ;
}