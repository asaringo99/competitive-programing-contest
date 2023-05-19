#include <bits/stdc++.h>
using namespace std ;
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
int C[101010] ;
vector<int> G[101010] ;
int cnt[101010] ;
vector<int> res ;

void dfs(int v , int prev){
    if(cnt[C[v]] == 0) res.push_back(v) ;
    cnt[C[v]]++ ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue;
        dfs(u,v) ;
    }
    cnt[C[v]]-- ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1) ;
    sort(res.begin(),res.end()) ;
    for(int u : res) cout << u + 1 << endl ;
}