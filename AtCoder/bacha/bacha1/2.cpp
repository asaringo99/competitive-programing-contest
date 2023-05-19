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
bool d[202020] ;
vector<int> res ;

void djikstra(){
    d[0] = true ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        res.push_back(v) ;
        d[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(!d[e.to]){
                d[e.to] = true ;
                que.push(P(e.cost,e.to)) ;
            }
        }
    }
}


int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back({v,v}) ;
        G[v].push_back({u,u}) ;
    }
    djikstra() ;
    rep(i,n){
        if(i == n - 1) cout << res[i] + 1 << endl ;
        else cout << res[i] + 1 << " " ;
    }
}