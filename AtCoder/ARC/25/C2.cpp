#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int to ;
    double cost ;
} ;

int n , m ;
double r , t ;

double d[3030] ;
vector<edge> G[3030] ;

ll djikstra(ll s){
    rep(i,n) d[i] = 1e16 ;
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
    double R[3030] , T[3030] ;
    rep(i,n){
        R[i] = d[i] / r ;
        T[i] = d[i] / t ;
    }
    sort(R,R+n) ;
    sort(T,T+n) ;
    ll sum = r < t ? 2*(1-n) : 1-n ;
    rep(i,n){
        int cnt = lower_bound(T,T+n,R[i]) - T ;
        sum += cnt ;
    }
    return sum ;
}

int main(){
    cin >> n >> m >> r >> t ;
    rep(i,m){
        int a , b ; double c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    ll res = 0 ;
    rep(i,n) res += djikstra(i) ;
    cout << res << endl ;
}