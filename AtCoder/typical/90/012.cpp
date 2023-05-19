#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int MAX_N = 2000 * 2000 + 7 ;

int H , W , q ;

bool used[MAX_N] ;
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

int main(){
    cin >> H >> W >> q ;
    UnionFind<int> uf(H * W + 7) ;
    for(int i = 0 ; i < q ; i++){
        int t ;
        cin >> t ;
        if(t == 1){
            int r , c ;
            cin >> r >> c ;
            r-- ;
            c-- ;
            int node = r * W + c ;
            used[node] = true ;
            if(r > 0 && used[node - W]) uf.unite(node,node-W) ;
            if(r < H - 1 && used[node + W]) uf.unite(node,node+W) ;
            if(c > 0 && used[node - 1]) uf.unite(node,node-1) ;
            if(c < W - 1 && used[node + 1]) uf.unite(node,node+1) ;
        }
        else{
            int ra , ca , rb , cb ;
            cin >> ra >> ca >> rb >> cb ;
            ra-- ;
            ca-- ;
            rb-- ;
            cb-- ;
            if(uf.same(ra * W + ca , rb * W + cb) && used[ra * W + ca] && used[rb * W + cb]) cout << "Yes" << endl ;
            else cout << "No" << endl ;
        }
    }
}