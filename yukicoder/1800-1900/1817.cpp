#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<int> G[101010] ;
int dp[101010][2] ;
int ep[101010] ;

void dfs(int v , int prev){
    int dir = 0 , rev = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        dir += dp[u][0] ;
        rev += dp[u][1] ;
        if(v < u) dir++ ;
        if(v > u) rev++ ;
    }
    dp[v][0] = dir ;
    dp[v][1] = rev ;
}

void rec(int v , int prev){
    if(prev == -1) ep[v] = dp[v][1] ;
    else ep[v] = ep[prev] - (int)(prev > v) + (int)(prev < v) ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        rec(u,v) ;
    }
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a ,b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ; rec(0,-1) ;
    rep(i,n) cout << ep[i] << endl ;
}