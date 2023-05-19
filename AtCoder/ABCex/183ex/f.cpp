#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 202020 ;

template<typename T>
struct UnionFind {
    T par[MAX_N] ; //親
    T lank[MAX_N] ; //木の深さ
    T volume[MAX_N] ; //木のサイズ
    unordered_map<int,int> mp[MAX_N] ;
    UnionFind(T n , vector<T> C){
        //n要素で初期化
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
            mp[i][C[i]]++ ;
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
            for(auto it : mp[x]) mp[y][it.first] += it.second ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
            volume[x] += volume[y] ;
            for(auto it : mp[y]) mp[x][it.first] += it.second ;
        }
    }

    bool same(T x , T y){
        return root(x) == root(y) ;
    }

    T size(T x){
        return volume[root(x)] ;
    }

    T query(T x , T y){
        return mp[root(x)][y] ;
    }
} ;

int n , q ;
vector<ll> C ;

int main(){
    cin >> n >> q ;
    rep(i,n){
        int c ;
        cin >> c ;
        C.push_back(c) ;
    }
    UnionFind<ll> uf(n,C) ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            int a , b ;
            cin >> a >> b ;
            a-- ; b-- ;
            uf.unite(a,b) ;
        }
        if(t == 2){
            int x , y ;
            cin >> x >> y ;
            x-- ;
            cout << uf.query(x,y) << endl ;
        }
    }
}