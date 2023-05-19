#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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

int n , m ;
ll C[101010] ;
TP X[202020] ;

int main(){
    cin >> n >> m ;
    UnionFind<ll> uf(n) ;
    ll res = 0 ;
    rep(i,n) cin >> C[i] , res += C[i] ;
    rep(i,m){
        ll a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        X[i] = {c,a,b} ;
    }
    sort(X,X+m) ;
    rep(i,m){
        ll a , b , c ;
        tie(c,a,b) = X[i] ;
        if(uf.same(a,b)) continue ;
        if(c <= max(C[uf.root(a)],C[uf.root(b)])){
            res -= max(C[uf.root(a)],C[uf.root(b)]) ;
            res += c ;
            C[uf.root(a)] = min(C[uf.root(a)],C[uf.root(b)]) ;
            C[uf.root(b)] = min(C[uf.root(a)],C[uf.root(b)]) ;
            uf.unite(a,b) ;
        }
    }
    cout << res << endl ;
}