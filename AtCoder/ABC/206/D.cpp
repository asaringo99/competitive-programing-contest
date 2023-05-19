#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 200007 ;

int n ;

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

int A[200007] ;
bool use[200007] ;

int main(){
    cin >> n ;
    UnionFind<int> uf(200007) ;
    rep(i,n) cin >> A[i] ;
    int res = 0 ;
    rep(i,n){
        uf.unite(A[i],A[n-1-i]) ;
    }
    memset(use,0,sizeof(use)) ;
    rep(i,200007){
        if(!use[uf.root(i)]) res += (uf.size(i) - 1) ;
        use[uf.root(i)] = true ;
    }
    cout << res << endl ;
}