#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
vector<int> G[101010] ;
ll dp[101010][2] ;

void rec(int v , int prev){
    ll white = 1 , black = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        rec(u,v) ;
        (white *= (dp[u][0] + dp[u][1])) %= mod ;
        (black *= dp[u][0]) %= mod ;
    }
    dp[v][0] = white ;
    dp[v][1] = black ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    rec(0,-1) ;
    cout << (dp[0][0] + dp[0][1]) % mod << endl ;
}