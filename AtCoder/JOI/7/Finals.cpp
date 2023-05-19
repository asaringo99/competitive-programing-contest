#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct UnionFind {
    vector<int> par ; //親
    vector<int> lank ; //木の深さ
    vector<int> volume ; //木のサイズ
    UnionFind(int n){
        //n要素で初期化
        par.resize(n) ;
        lank.resize(n) ;
        volume.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    int root(int x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(int x , int y){
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

    bool same(int x , int y){
        return root(x) == root(y) ;
    }

    int size(int x){
        return volume[root(x)] ;
    }
} ;

int n , m , k ;
TP E[101010] ;

int main(){
    cin >> n >> m >> k ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        E[i] = {c,a,b} ;
    }
    UnionFind uf(n) ;
    ll res = 0 , cnt = n - k ;
    sort(E,E+m) ;
    rep(i,m){
        if(cnt == 0) break ;
        auto[c,a,b] = E[i] ;
        if(uf.same(a,b)) continue;
        uf.unite(a,b) ;
        res += c ;
        cnt-- ;
    }
    cout << res << endl ;
}