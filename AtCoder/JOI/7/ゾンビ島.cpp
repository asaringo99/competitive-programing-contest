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

int n , m , k , s ;
ll p , q ;

vector<int> G[202020] ;
ll d[202020] ;
int K[101010] ;
bool R[101010] ;
bool T[101010] ;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        auto[dist,v] = que.top() ; que.pop() ;
        if(d[v] < dist) continue;
        for(int u : G[v]){
            if(T[u]) continue;
            ll cost ;
            cost = p ;
            if(R[u]) cost = q ;
            if(d[u] > d[v] + cost){
                d[u] = d[v] + cost ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}


ll D[101010] ;
void bfs(){
    rep(i,n) D[i] = 1e16 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    rep(i,k){
        D[K[i]] = 0 ;
        que.push(P(0,K[i])) ;
    }
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(D[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(D[u] > D[v] + 1){
                D[u] = D[v] + 1 ;
                que.push(P(D[u],u)) ;
            }
        }
    }
    rep(i,n) if(D[i] <= s) R[i] = true ;
}

int main(){
    cin >> n >> m >> k >> s >> p >> q ;
    rep(i,k) cin >> K[i] , K[i]-- , T[K[i]] = true ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    bfs() ;
    djikstra() ;
    cout << d[n-1] - (R[n-1] ? q : p) << endl ;
}