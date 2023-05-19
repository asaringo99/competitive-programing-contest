#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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

int n , k , l ;
map<P,int> mp ;

int main(){
    cin >> n >> k >> l ;
    UnionFind<ll> uf1(n) , uf2(n) ;
    rep(i,k){
        int p , q ;
        cin >> p >> q ;
        p-- ; q-- ;
        uf1.unite(p,q) ;
    }
    rep(i,l){
        int p , q ;
        cin >> p >> q ;
        p-- ; q-- ;
        uf2.unite(p,q) ;
    }
    rep(i,n) mp[P(uf1.root(i),uf2.root(i))]++ ;
    rep(i,n) cout << mp[P(uf1.root(i),uf2.root(i))] << " " ;
    cout << endl ;
}