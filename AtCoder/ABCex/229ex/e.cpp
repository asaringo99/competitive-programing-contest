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

template<typename T>
struct UnionFind {
    vector<T> par ; //親
    vector<T> lank ; //木の深さ
    vector<T> volume ; //木のサイズ
    UnionFind(T n){
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
vector<int> G[202020] ;
int res[202020] ;

int main(){
    cin >> n >> m ;
    UnionFind<ll> uf(n) ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[b].push_back(a) ;
        G[a].push_back(b) ;
    }
    set<int> st ;
    for(int i = n - 1 ; i >= 0 ; i--){
        res[i] = st.size() ;
        for(int j = 0 ; j < G[i].size() ; j++){
            int u = G[i][j] ;
            if(st.count(uf.root(u)) == 1){
                st.erase(uf.root(u)) ;
                uf.unite(i,u) ;
            }
        }
        st.insert(uf.root(i)) ;
    }
    rep(i,n) cout << res[i] << endl ;
}