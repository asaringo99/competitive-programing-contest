#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
vector<int> G[100007] ;
ll dp[100007] ;
ll ans[100007] ;
vector<ll> rem[100007] ;
vector<ll> S[100007] ;
vector<ll> T[100007] ;
map<int,int> nod[100007] ;

void dfs(int v , int prev){
    ll res = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u != prev){
            dfs(u,v) ;
            res *= (dp[u] + 1) ;
            res %= m ;
        }
    }
    dp[v] = res ;
    return ;
}

void rec(int v , int prev){
    if(prev == -1){
        ans[v] = dp[v] ;
        int siz = G[v].size() ;
        S[v].push_back(1) ;
        T[v].push_back(1) ;
        for(int i = 0 ; i < siz ; i++){
            int u = G[v][i] ;
            int w = G[v][siz-1-i] ;
            S[v].push_back(S[v][i] * (dp[u] + 1) % m) ;
            T[v].push_back(T[v][i] * (dp[w] + 1) % m) ;
            nod[v][u] = i + 1 ;
        }
    }
    else{
        int num = nod[prev][v] ;
        ll tmp = (S[prev][num-1] * T[prev][T[prev].size()-num-1] + 1) % m ;
        ans[v] = dp[v] * tmp % m ;
        int siz = G[v].size() ;
        S[v].push_back(1) ;
        T[v].push_back(1) ;
        for(int i = 0 ; i < siz ; i++){
            int u = G[v][i] ;
            int w = G[v][siz-1-i] ;
            if(u != prev) S[v].push_back(S[v][i] * (dp[u] + 1) % m) ;
            else S[v].push_back(S[v][i] * tmp % m) ;
            if(w != prev) T[v].push_back(T[v][i] * (dp[w] + 1) % m);
            else T[v].push_back(T[v][i] * tmp % m) ;
            nod[v][u] = i + 1 ;
        }
    }

    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u != prev) rec(u,v) ;
    }
}

int main(){
    memset(dp,0,sizeof(dp)) ;
    cin >> n >> m ;
    rep(i,n-1){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    dfs(0,-1) ;
    rec(0,-1) ;
    rep(i,n){
        cout << ans[i] << endl ;
    }
}