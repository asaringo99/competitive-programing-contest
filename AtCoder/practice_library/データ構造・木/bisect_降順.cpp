#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_M (ll)100
#define MAX_N 300
#define INF (ll)1e5

int n , x ;

//降順二分探索
int bisect(vector<int> A , int x){
  int lef = 0 , rig = A.size() ;
  int m ;
  while(rig - lef > 0){
    m = (lef + rig) / 2 ;
    if(A[m] == x) return m ;
    if(A[m] > x) lef = m + 1 ;
    if(A[m] < x) rig = m;
  }
  return rig ;
}