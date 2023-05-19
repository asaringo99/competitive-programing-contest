#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

int n ;
vector<edge> G[101010] ;
ll d[101010] ;

void dfs(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(e.to == prev) continue;
        d[e.to] = d[v] + e.cost ;
        dfs(e.to,v) ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    dfs(0,-1) ;
    rep(i,n) {
        if(d[i] % 2 == 0) cout << '0' << endl ;
        else cout << '1' << endl ;
    }
}