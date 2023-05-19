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

int n ;

vector<int> G[202020] ;
ll dp[202020] ;
ll par[202020] ;
ll ep[202020] ;
ll chi[202020] ;

void dfs(int v , int prev){
    ll res = 0 , nod = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue;
        dfs(u,v) ;
        res += dp[u] + par[u] ;
        nod += par[u] ;
    }
    dp[v] = res ;
    par[v] = nod ;
}

void rec(int v , int prev){
    if(v == 0) ep[v] = dp[v] ;
    else ep[v] = ep[prev] + n - 2 * par[v] ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue;
        rec(u,v) ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    rec(0,-1) ;
    rep(i,n) cout << ep[i] << endl ;
}