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
vector<edge> G[202020] ;
ll D[202020] ;
ll dp[202020][2] ;
int nov[202020] ;
ll ep[202020] ;
ll res[202020] ;

void dfs(int v , int prev){
    ll res = 0 , tes = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(e.to == prev) continue ;
        dfs(e.to,v) ;
        if(res <= dp[e.to][0] + e.cost) res = dp[e.to][0] + e.cost ;
        if(res <= D[e.to] + e.cost) res = D[e.to] + e.cost ;
        if(res > tes) {
            swap(tes,res) ;
            nov[v] = e.to ;
        }
    }
    dp[v][0] = tes ;
    dp[v][1] = res ;
}

void rec(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(e.to == prev) continue ;
        if(e.to == nov[v]) ep[e.to] = max({dp[v][1]+e.cost,ep[v]+e.cost,D[v]+e.cost}) ;
        else ep[e.to] = max({dp[v][0]+e.cost,ep[v]+e.cost,D[v]+e.cost}) ;
        rec(e.to,v) ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int a , b ; ll c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    rep(i,n) cin >> D[i] ;
    dfs(0,-1) ;
    rec(0,-1) ;
    rep(i,n) cout << max(dp[i][0],ep[i]) << endl ;
}