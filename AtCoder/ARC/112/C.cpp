#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

vector<int> G[101010] ;
int child[101010] ;
ll dp[101010] ;

void dfs(int v , int prev){
    ll res = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        res += child[u] ;
    }
    child[v] = res ;
    return ;
}

void rec(int v , int prev){
    dp[v] = 1 ;
    vector<int> odd , eve ;
    ll res = 0 , val = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        rec(u,v) ;
        if(child[u] % 2 == 0 && dp[u] <= 0) res += dp[u] ;
        if(child[u] % 2 == 0 && dp[u] > 0) val += dp[u] ;
        if(child[u] % 2 == 1) odd.push_back(dp[u]) ;
    }
    sort(odd.begin(),odd.end()) ;

    rep(i,odd.size()) {
        if(i % 2 == 0) res += odd[i] ;
        if(i % 2 == 1) res -= odd[i] ;
    }
    if(odd.size() % 2 == 0) res += val ;
    if(odd.size() % 2 == 1) res -= val ;
    dp[v] += res ;
    return ;
}

int main(){
    cin >> n ;
    rrep(i,1,n){
        int p ;
        cin >> p ;
        p-- ;
        G[i].push_back(p) ;
        G[p].push_back(i) ;
    }
    dfs(0,-1) ;
    rec(0,-1) ;
    cout << (dp[0] + n) / 2 << endl ;
}