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

int n , q ;
int A[202020] ;
vector<int> G[202020] ;
vector<P> vec[202020] ;
int D[202020] ;
int res[202020] ;

void dfs(int v , int prev , int dep){
    vector<int> V ;
    for(P p : vec[v]){
        auto[dist,id] = p ;
        V.push_back(D[dist]) ;
    }
    D[dep]++ ;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,dep+1) ;
    }
    rep(i,vec[v].size()){
        auto[dist,id] = vec[v][i] ;
        res[id] = D[dist] - V[i] ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n) {
        int p ;
        cin >> p ;
        p-- ;
        G[p].push_back(i) ;
        G[i].push_back(p) ;
    }
    cin >> q ;
    rep(i,q){
        int u , d ;
        cin >> u >> d ;
        u-- ;
        vec[u].push_back(P(d,i)) ;
    }
    dfs(0,-1,0) ;
    rep(i,q) cout << res[i] << endl ;
}