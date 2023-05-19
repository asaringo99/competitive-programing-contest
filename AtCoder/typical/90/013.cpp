#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , m ;

const int MAX_N = 100007 ;

struct edge
{
    int to ;
    ll cost ;
};

vector<edge> G[MAX_N] ;

template<typename T>
struct djikstra {
    ll d[MAX_N] ;
    void root(int k){
        fill(d,d+MAX_N,INT_MAX) ;
        d[k] = 0 ;
        priority_queue<P,vector<P>,greater<P>> que ;
        que.push(P(0,k)) ;
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
    }
};


int main(){
    cin >> n >> m ;
    djikstra<ll> slv1 , slv2 ;
    for(int i = 0 ; i < m ; i++){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    slv1.root(0) ;
    slv2.root(n-1) ;
    for(int i = 0 ; i < n ; i++){
        cout << slv1.d[i] + slv2.d[i] << endl ;
    }
}