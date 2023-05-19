#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

// セグメント木

const int MAX_N = 1 << 17 ;
const int INF = INT_MAX ;

int dat[2 * MAX_N - 1] ;
int lazy[2 * MAX_N - 1] ;

int n ;

//コンストラクタ
void init(int n){
    ll p ;
    while(p < n) p *= 2 ;
    for(int i = 0 ; i < 2 * p - 1 ; i++)  dat[i] = 0 ;
}

// 値の更新
void update(int x , int value){
    x += n - 1 ;
    dat[x] = value ;
    while(x > 0){
        x /= 2 ;
        dat[x] = min(dat[2*x+1],dat[2*x+2]) ;
    }
}

// 区間の更新
void add(int a , int b , int k , int l , int r , int value){
    if(a <= l && r <= b) lazy[k] = value ;
    if(r <= a || b <= l) return ;
    add(a,b,2*k+1,l,(l+r)/2,value) ;
    add(a,b,2*k+2,(l+r)/2,r,value) ;
}

void eval(int k , int l , int r){
    
}

// クエリ処理
int query(int a , int b , int k , int l , int r){
    if(a <= l && r <= r) return dat[k] ;
    if(r <= a || b <= l) return INF ;

    int lv = query(a,b,2*k+1,l,(l+r)/2) ;
    int rv = query(a,b,2*k+2,(l+r)/2,r) ;
    return min(lv,rv) ;
}

