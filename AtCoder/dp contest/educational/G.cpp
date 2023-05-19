#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;
vector<int> G[MAX_N] ;
int d[MAX_N] ;

set<int> in ;

int dfs(int v){
    if(G[v].size() == 0) return d[v] = 0 ;
    if(d[v] != -1) return d[v] ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        res = max(res,dfs(u) + 1) ;
    }
    return d[v] = res ;
}

int main(){
    memset(d,-1,sizeof(d)) ;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
        in.insert(y) ;
    }
    vector<int> out ;
    for(int i = 0 ; i < n ; i++){
        if(in.count(i) == 0) {
            out.push_back(i) ;
        }
    }
    for(int u : out) dfs(u) ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++) res = max(res,d[i]) ;
    cout << res << endl ;
}