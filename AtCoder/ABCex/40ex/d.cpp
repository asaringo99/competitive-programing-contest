#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int from , to ;
} ;

const int MAX_N = 101010 ;

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

int n , m , q ;
vector<edge> G[202020] ;
vector<P> query[202020] ;
ll res[101010] ;

int main(){
    cin >> n >> m ;
    UnionFind<ll> uf(n) ;
    rep(i,m){
        int a , b , y ;
        cin >> a >> b >> y ;
        a-- ; b-- ;
        G[y].push_back(edge{a,b}) ;
    }
    cin >>q ;
    rep(i,q){
        int v , w ;
        cin >> v >> w ;
        v-- ;
        query[w].push_back(P(i,v)) ;
    }
    for(int i = 200000 ; i >= 0 ; i--){
        for(P p : query[i]) res[p.first] = uf.size(p.second) ;
        for(edge e : G[i]) uf.unite(e.from,e.to) ;
    }
    rep(i,q) cout << res[i] << endl ;
}