#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

ll n , m ;
P E[101010] ;
ll ans[101010] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    UnionFind uf(n) ;

    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        E[i] = P(a,b);
    }
    ll res = n * (n - 1) / 2 ;
    rep(i,m){
        ans[m-1-i] = res ;
        auto [a,b] = E[m-1-i] ;
        if(uf.same(a,b)) continue ;
        res -= (ll)(uf.size(a)) * (ll)(uf.size(b)) ;
        uf.unite(a,b) ;
    }
    rep(i,m) cout << ans[i] << endl ;
}