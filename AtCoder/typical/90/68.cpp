#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 2000000 ;

int n , q ;
int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ
int volume[MAX_N] ; //木のサイズ

template<typename T>
struct UnionFind {
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

ll res[101010] ;
ll add[101010] ;
vector<TP> query ;

int main(){
    cin >> n >> q ;
    UnionFind<int> uf(101010) ;
    for(int i = 0 ; i < q ; i++){
        int t , x , y , v ;
        cin >> t >> x >> y >> v ;
        if(t == 0){
            uf.unite(x,y) ;
            add[y] = v ;
        }
        else{
            if(!uf.same(x,y)) query.push_back({-1,x,y,v}) ;
            else query.push_back({1,x,y,v}) ;
        }
    }
    for(int i = 1 ; i < n ; i++) if(uf.same(i,i+1)) res[i+1] = add[i+1] - res[i] ;
    for(int i = 0 ; i < query.size() ; i++){
        int que , x , y , v ;
        tie(que,x,y,v) = query[i] ;
        if(que == -1) cout << "Ambiguous" << endl ;
        else{
            if(abs(x-y) % 2 == 1) cout << res[y] - (v - res[x]) << endl ;
            if(abs(x-y) % 2 == 0) cout << res[y] + (v - res[x]) << endl ;
        }
    }
}