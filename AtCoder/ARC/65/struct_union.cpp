#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 200005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k , l ;

template<typename T>
struct UnionFind {
    T par[MAX_N] ; //親
    T lank[MAX_N] ; //木の深さ
    T volume[MAX_N] ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    T root(T x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(T x , T y){
        x = root(x);
        y = root(y) ;
        if(x == y) return ;

        if(lank[x] < lank[y]){
            par[x] = y ;
            volume[y] += volume[x] ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
            volume[x] += volume[y] ;
        }
    }

    bool same(T x , T y){
        return root(x) == root(y) ;
    }

    T size(T x){
        return volume[root(x)] ;
    }
} ;

int main(){
    cin >> n >> k >> l ;
    UnionFind<int> uf1(n) , uf2(n) ;
    for(int i = 0 ; i < k ; i++){
        int p , q ;
        cin >> p >> q ;
        p-- ;
        q-- ;
        uf1.unite(p,q) ;
    }
    for(int i = 0 ; i < l ; i++){
        int p , q ;
        cin >> p >> q ;
        p-- ;
        q-- ;
        uf2.unite(p,q) ;
    }
    map<pair<int,int>,int> rem ;
    for(int i = 0 ; i < n ; i++){
        pair<int,int> P(uf1.root(i),uf2.root(i)) ;
        rem[P]++ ;
    }
    for(int i = 0 ; i < n ; i++){
        pair<int,int> P(uf1.root(i),uf2.root(i)) ;
        cout << rem[P] << " " ;
    }
    cout << endl ;
}