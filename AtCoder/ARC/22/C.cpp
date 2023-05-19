#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<int> G[101010] ;
int dp[101010] ;
int sp[101010] ;

void dfs(int v , int prev , int dep){
    dp[v] = dep ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v,dep+1) ;
    }
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1,0) ;
    int node = -1 , val = -1 ;
    rep(i,n) if(val < dp[i]){
        node = i ;
        val = dp[i] ;
    }
    memset(dp,0,sizeof(dp)) ;
    dfs(node,-1,0) ;
    int res = -1 , v = -1 ;
    rep(i,n) if(res < dp[i]){
        res = dp[i] ;
        v = i ;
    }
    cout << node + 1 << " " << v + 1 << endl ;
}