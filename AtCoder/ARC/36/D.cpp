#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 202020 ;

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

int n , q ;

int main(){
    cin >> n >> q ;
    UnionFind<ll> uf(2*n);
    rep(i,q){
        int w , x , y , z ; 
        cin >> w >> x >> y >> z ;
        x-- ; y-- ;
        if(w == 1){
            if(z % 2 == 0) {uf.unite(x,y) , uf.unite(n+x,n+y) ;}
            if(z % 2 == 1) uf.unite(x,n+y) , uf.unite(n+x,y) ;
        }
        if(w == 2){
            if(uf.same(x,y)) cout << "YES" << endl ;
            else cout << "NO" << endl ;
        }
    }
}