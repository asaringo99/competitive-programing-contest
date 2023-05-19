#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

const int MAX_N = 1 << 17 ;
const int INF = INT_MAX ;

int n ;
int dat[2 * MAX_N - 1] ;

// セグメント木

// コンストラクタ
void init(int p){
    n = 1 ;
    while(n < p) n *= 2 ;
    for(int i = 0 ; i < 2 * n - 1 ; i++) dat[i] = INF ;
}

//値の更新
void update(int x , int value){
    x += n - 1 ;
    dat[x] = value ;
    while(x > 0){
        x = (x - 1) / 2 ;
        dat[x] = min(dat[2*x+1],dat[2*x+2]) ;
    }
}

//クエリの処理
int query(int a , int b , int k , int l , int r){
    if(r <= a || b <= l) return INF ;
    if(a <= l && r <= b) return dat[k] ;
    else{
        int lef = query(a,b,2*k+1,l,(l+r)/2) ;
        int rig = query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
}