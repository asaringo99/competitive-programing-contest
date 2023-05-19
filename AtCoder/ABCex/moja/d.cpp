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
int d[101010] , par[101010] ;
vector<int> G[101010] ;
vector<int> A ;
priority_queue<P> que ;

void dfs(int v , int prev){
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue;
        dfs(u,v) ;
        chmax(res,d[u]+1) ;
    }
    d[v] = res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n){
        int p ;
        cin >> p ;
        p-- ;
        par[i] = p ;
        G[i].push_back(p) ;
        G[p].push_back(i) ;
    }
    dfs(0,-1) ;
    for(int u : G[0]) que.push(P(d[u],u)) ;
    int count = 0 ;
    while(!que.empty()){
        auto [dep,v] = que.top() ;
        if(dep - count < 0) break ;
        que.pop() ;
        for(int u : G[v]) if(u != par[v]) que.push(P(d[u],u)) ;
        count++ ;
    }
    cout << count << endl ;
}