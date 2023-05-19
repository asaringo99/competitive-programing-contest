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

int n , m ;

vector<int> G[303030] ;
vector<bool> F ;
vector<int> d , e ;

void djikstra(vector<int> &d , int s){
    rep(i,n) d[i] = 1e9 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    F.resize(n) ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        if(u == 0){
            v-- ;
            F[v] = true ;
        }
        else{
            u-- ; v-- ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }
    }
    d.resize(n) ;
    e.resize(n) ;
    djikstra(d,0) ;
    djikstra(e,n-1) ;
    int dist = d[n-1] ;
    int ret = 1e9 ;
    int rem = 1e9 ;
    rep(i,n) if(F[i]) chmin(ret,d[i]) ;
    rep(i,n) if(F[i]) chmin(rem,e[i]) ;
    rep(i,n){
        int res = min({dist,ret+e[i]+1,ret+rem+2,rem+d[i]+1}) ;
        if(res == 1e9) cout << -1 << " " ;
        else cout << res << " " ;
    }
    cout << endl ;
}