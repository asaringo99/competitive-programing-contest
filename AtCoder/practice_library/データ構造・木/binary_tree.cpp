#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8

struct node{
  int val ;
  node *lch , *rch ;
} ;

//数xを追加
node *insert(node *p , int x){
  if(p == NULL){
    node *q = new node ;
    q->val = x ;
    q->lch = q->rch = NULL ;
    //アドレスを返す
    return q ;
  }
  else{
    if(x < p->val) p->lch = insert(p->lch , x) ;
    else p->rch = insert(p->rch , x) ;
    //アドレスを返す
    return p ;
  }
}

// xを検索
bool find(node *p , int x){
  if(p == NULL) return false ;
  else if(x == p->val) return true ;
  else if(x < p->val) return find(p->lch,x) ;
  else return find(p->rch,x) ;
}

node *remove(node *p , int x){
  if(p == NULL) return NULL ;
  // xがあるノードまで移動する
  else if(x < p->val) p->lch = remove(p->lch,x) ;
  else if(x > p->val) p->rch = remove(p->rch,x) ;

  //3pattern
  else if(p->lch == NULL){
    //ノード置き換え
    node *q = p->rch ;
    delete p ;
    return q ;
  }

  else if(p->lch->rch == NULL){
    node *q = p->lch ;
    q->rch = p->rch ;
    delete p ;
    return q ;
  }

  else{
    node *q ;
    for(q = p->lch ; q->rch->rch != NULL ; q = q->rch) ;
    node *r = q->rch ;
    q->rch = r->lch ;
    r->lch = p->lch ;
    r->rch = p->rch ;
    delete p ;
    return r ;
  }
  return p ;
}