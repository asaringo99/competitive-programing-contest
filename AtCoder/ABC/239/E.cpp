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

int n , q ;
int X[101010] ;
vector<int> G[101010] ;
vector<P> query[101010] ;
vector<int> vec ;
int in[101010] , out[101010] ;
int res[101010] ;

int t = 0 ;
vector<int> dfs(int v , int prev){
    vector<int> vec = {X[v]} ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        vector<int> ret = dfs(u,v) ;
        for(int u : ret) vec.push_back(u) ;
    }
    sort(vec.begin(),vec.end(),greater<int>()) ;
    int m = vec.size() ;
    vector<int> A ;
    for(int i = 0 ; i < min(20,m) ; i++) A.push_back(vec[i]) ;
    for(P p : query[v]) res[p.second] = A[p.first] ;
    return A ;
}

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> X[i] ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    rep(i,q){
        int v , k ;
        cin >> v >> k ;
        v-- ;
        k-- ;
        query[v].push_back(P(k,i)) ;
    }
    dfs(0,-1) ;
    rep(i,q) cout << res[i] << endl ;
}