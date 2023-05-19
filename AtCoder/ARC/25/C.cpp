#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int to ;
    ll cost ; 
};

int n , m , r , t ;
vector<edge> G[3000] ;

ll dijkstra(int s){
    ll d[3000] ;
    rep(i,n) d[i] = 1e17 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
    ll turtle[3000] , rabbit[3000] ;
    rep(i,n) turtle[i] = d[i] * r ;
    sort(turtle,turtle+n) ;
    ll res = 1 - n ;
    rep(i,n){
        if(i == s) continue ;
        ll val = (double)d[i] * t ;
        int id = lower_bound(turtle,turtle+n,val) - turtle ;
        res += id ;
        if(r < t) res-- ;
    }
    return res ;
}

int main(){
    cin >> n >> m >> r >> t ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back({b,c}) ;
        G[b].push_back({a,c}) ;
    }
    ll res = 0 ;
    rep(i,n) res += dijkstra(i) ;
    cout << res << endl ;
}