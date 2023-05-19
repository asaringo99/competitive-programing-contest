#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , m ;
ll d[202020] ;
ll dp[202020] ;
vector<int> G[202020] ;

void bfs(){
    rep(i,n) d[i] = INT_MAX ;
    d[0] = 0 ;
    dp[0] = 1 ;
    queue<ll> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ;
        que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] == d[v] + 1) (dp[u] += dp[v]) %= mod ;
            if(d[u] > d[v] + 1){
                dp[u] = dp[v] % mod ;
                d[u] = d[v] + 1 ;
                que.push(u) ;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    cout << dp[n-1] << endl;
}