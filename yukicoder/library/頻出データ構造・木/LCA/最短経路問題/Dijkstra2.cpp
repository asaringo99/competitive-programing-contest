#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8
#define INF (ll)1e8
typedef pair<int,int> P ;

struct edge{int to , cost ;} ;
vector<edge> G[MAX_N] ;
int d[MAX_N] ;
int n ;

void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P>> que ;
  fill(d,d+n,INF) ;
  d[s] = 0 ;
  que.push(P(0,s)) ;
  while(!que.empty()){
    P p = que.top() ;
    que.pop() ;
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