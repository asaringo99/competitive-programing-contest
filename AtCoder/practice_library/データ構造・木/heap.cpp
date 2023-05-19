#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8

int heap[MAX_N] , sz = 0 ;

void push(int x){
  //自分のノード番号
  int i = sz++ ;

  while(i > 0){
    //親のノードの番号
    int p = (i - 1) / 2 ;

    if(heap[p] <= x) break ;

    //親のノードの数字を下ろして自分は上に
    heap[i] = heap[p] ;
    i = p ;
  }
  heap[i] = x ;
}

void pop(){
  //根に持ってくる値
  int x = heap[--sz] ;

  //根から下ろしていく
  int i = 0 ;
  while(i * 2 + 1 < sz){
    //子同士を比較
    int a = i * 2 + 1 , b = i * 2 + 2 ;
    if(b < sz && heap[b] < heap[a]) a = b ;

    // もう逆転しているなら終わり
    if(heap[a] >= x) break ;

    // 子を持ち上げる
    heap[i] = heap[a] ;
    i = a ;
  }
  heap[i] = x ;
}

int find(){
  return heap[0] ;
}

int main(){
  for(int i = 0 ; i < 50 ; i++) push(i+1) ;
  pop() ;
  cout << find() << endl ;
}