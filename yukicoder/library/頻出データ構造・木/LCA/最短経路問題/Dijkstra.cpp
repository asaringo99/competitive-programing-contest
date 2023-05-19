#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using Pair = pair<int,int> ;
using ll = long long ;
using que = queue<Pair> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_V 100
#define INF 100000

bool used[MAX_V] ;
int d[MAX_V] ;
int cost[MAX_V][MAX_V] ;
int V ;

void dijkstra(int s){
  fill(d,d+V,INF) ;
  fill(used,used+V,false) ;
  d[s] = 0 ;
  while(true){
    int v = -1 ;
    for(int u = 0 ; u < V ; u++){
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u ;
    }
    if(v == -1) break ;
    used[v] = true ;

    for(int u = 0 ; u < V ; u++){
      d[u] = min(d[u],d[v] + cost[v][u]) ;
    }
  }
}