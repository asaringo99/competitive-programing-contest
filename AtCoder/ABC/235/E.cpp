#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
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

int n , m , q ;
TP X[404040] ;
bool res[202020] ;

int main(){
    cin >> n >> m >> q ;
    UnionFind<ll> uf(n) ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        X[i] = {c,a,b,0,-1} ;
    }
    rrep(i,m,m+q){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        X[i] = {c,a,b,1,i-m} ;
    }
    sort(X,X+m+q) ;
    rep(i,m+q){
        int cost , a , b , t , id ;
        tie(cost,a,b,t,id) = X[i] ;
        if(t == 0) uf.unite(a,b) ;
        if(t == 1){
            if(uf.same(a,b)) res[id] = false ;
            else res[id] = true ;
        }
    }
    rep(i,q) {
        if(res[i]) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}