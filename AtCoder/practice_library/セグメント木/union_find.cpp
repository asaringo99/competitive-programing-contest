#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ

//n要素で初期化

void init(int n) {
  for(int i = 0 ; i < n ; i++){
    par[i] = i ;
    lank[i] = 0 ;
  }
}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x ;
  } else{
    return par[x] = find(par[x]) ;
  }
}

//xとyの属する集合を合併
void unite(int x , int y){
  x = find(x) ;
  y = find(y) ;
  if(x == y) return ;

  if(lank[x] < lank[y]){
    par[x] = y ;
  } else {
    par[y] = x ;
    if(lank[x] == lank[y]) lank[x]++ ;
  }
}

bool same(int x , int y){
  return find(x) == find(y) ;
}

int main(){
  int a = 1 , b = 2 , c = 3 , d = 4 ;
  init(4) ;
  unite(a,b) ;
  unite(c,d) ;
  unite(a,d) ;
  cout << lank[a] << endl ;
}