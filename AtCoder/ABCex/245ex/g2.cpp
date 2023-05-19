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

int n , m , k , L ;
int A[101010] , B[101010] , D[101010] ;
ll res[101010] , d[101010] ;
vector<int> vec , C[101010] ;
vector<edge> G[101010] ;
bool used[101010] ;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    for(int u : vec){
        d[u] = 0 ;
        que.push(P(0,u)) ;
    }
    while(!que.empty()){
        auto [dist,v] = que.top() ; que.pop() ;
        if(dist > d[v]) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k >> L ;
    rep(i,n) cin >> A[i] ;
    rep(i,L) cin >> B[i] , B[i]-- ;
    rep(i,m){
        int u , v ;
        ll cost ;
        cin >> u >> v >> cost ;
        u-- ; v-- ;
        G[u].push_back(edge{v,cost}) ;
        G[v].push_back(edge{u,cost}) ;
    }
    rep(i,n) res[i] = 1e16 ;
    rep(S,18){
        vec = {} ;
        rep(i,L) if(A[B[i]] >> S & 1) vec.push_back(B[i]) ;
        djikstra() ;
        rep(i,n) if(!(A[i] >> S & 1)) chmin(res[i],d[i]) ;
    }
    rep(S,18){
        vec = {} ;
        rep(i,L) if(!(A[B[i]] >> S & 1)) vec.push_back(B[i]) ;
        djikstra() ;
        rep(i,n) if(A[i] >> S & 1) chmin(res[i],d[i]) ;
    }
    rep(i,n) {
        ll ans = res[i] == 1e16 ? -1 : res[i] ;
        cout << ans << " " ;
    }
    cout << endl ;
}