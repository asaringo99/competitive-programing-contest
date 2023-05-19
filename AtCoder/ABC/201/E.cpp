#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int mod = 2000000014 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res = (res * x) % mod ;
        x = (x * x) % mod ;
        n >>= 1 ;
    }
    return res ;
}

struct edge
{
    int to ;
    ll cost ;
};

vector<edge> G[200005] ;

int n ;

ll d[200005] ;
bool used[200005] ;

void dfs(int v , ll cost){
    used[v] = true ;
    d[v] = cost ;
    // cout << v << " " << d[v] << endl ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(!used[e.to]) dfs(e.to , cost ^ e.cost) ;
    }
}

int main(){
    cin >> n ;
    memset(d,0,sizeof(d)) ;
    memset(used,0,sizeof(used)) ;
    for(int i = 0 ; i < n - 1 ; i++){
        int u , v ;
        ll w ;
        cin >> u >> v >> w ;
        u-- ;
        v-- ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    dfs(0,0) ;
    vector<int> X(61,0) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 61 ; j++){
            if(d[i] >> j & 1) X[j]++ ;
        }
    }
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        vector<int> dd ;
        ll val = d[i] ;
        for(int j = 0 ; j < 61 ; j++){
            if(val >> j & 1) dd.push_back(1) ;
            else dd.push_back(0) ;
        }
        for(int j = 0 ; j < 61 ; j++){
            if(dd[j] == 0) (res += X[j] * powmod(2,j)) %= mod ;
            else (res += (n - X[j]) * powmod(2,j)) %= mod ;
        }
    }
    cout << (res / 2) % 1000000007 << endl ;
}