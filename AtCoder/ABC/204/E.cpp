#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

struct edge
{
    int to ;
    ll c , d ;
};

vector<edge> G[100007] ;
ll d[100007] ;

ll calculation(ll m , ll dist , ll tim){
    return m + dist / (m + tim + 1);
}

void dijkstra(){
    fill(d,d+100007,LLONG_MAX) ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            ll tim = sqrt(e.d) , val = LLONG_MAX ;
            for(int i = tim - 1000 ; i <= tim + 1000 ; i++){
                if(i < d[v]) continue ;
                if(val > i - d[v] + e.d / (i + 1)){
                    val = i - d[v] + e.d / (i + 1) ;
                }
            }
            if(val == LLONG_MAX) val = d[v] ;
            if(d[e.to] > d[v] + e.c + val){
                d[e.to] = d[v] + e.c + val ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,c,d}) ;
        G[b].push_back(edge{a,c,d}) ;
    }
    dijkstra() ;
    ll ans = d[n-1] == LLONG_MAX ? -1 : d[n-1] ;
    cout << ans << endl ;
}