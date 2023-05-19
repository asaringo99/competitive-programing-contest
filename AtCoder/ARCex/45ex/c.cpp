#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

int n , x ;
vector<edge> G[101010];
ll d[101010] ;
unordered_map<ll,ll> mp ;

void dfs(int v , int prev){
    mp[d[v]]++ ;
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
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    dfs(0,-1) ;
    ll res = 0 ;
    rep(i,n) res += mp[d[i]^x] ;
    if(x == 0) res -= n ;
    cout << res / 2 << endl ;
}