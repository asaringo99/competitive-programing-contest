#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
const int mod = 1000000007 ;
const int MAX_N = 100007 ;

vector<int> G[MAX_N] ;
bool used[MAX_N] ;

ll dp[MAX_N][2] ; // 白 : 0 , 黒 : 1

void dfs(int v){
    if(v != 0 && G[v].size() == 1){
        dp[v][0] = 1 ;
        dp[v][1] = 1 ;
    }
    used[v] = true ;
    ll white = 1 , black = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!used[u]){
            dfs(u) ;
            (white *= (dp[u][0] + dp[u][1])) %= mod ;
            (black *= dp[u][0]) %= mod ;
        }
    }
    dp[v][0] = white ;
    dp[v][1] = black ;
}

int main(){
    memset(used,0,sizeof(used)) ;
    memset(dp,0,sizeof(dp)) ;
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0) ;
    cout << (dp[0][0] + dp[0][1]) % mod << endl ;
}