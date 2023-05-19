#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8
#define INF (ll)1e8

int cost[MAX_N][MAX_N] ;
int mincost[MAX_N] ;
bool used[MAX_N] ;
int n ;

int prim(int s){
  fill(mincost,mincost+n,INF) ;
  fill(used,used+n,false) ;
  mincost[s] = 0 ;
  int res = 0 ;

  while(true){
    int v = -1 ;
    for(int u = 0 ; u < n ; u++){
      if(!used[u] && (v = -1 || mincost[u] < mincost[v])) v = u ;
    }

    if(v == -1) break ;
    used[v] = true ;
    res += mincost[v] ;

    for(int u = 0 ; u < n ; u++){
      mincost[u] = min(mincost[u],cost[v][u]) ;
    }
  }

  return res ;
}