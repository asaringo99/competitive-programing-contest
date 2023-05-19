#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

struct UnionFind {
    vector<int> par ; //親
    vector<int> lank ; //木の深さ
    vector<int> volume ; //木のサイズ
    void init(int n){
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
TP E[303030] ;
int res[303030] ;
UnionFind uf[10101];

int main(){
    // fast_input_output;
    cin >> n >> m >> k ;
    rep(i,k) uf[i].init(n);
    rep(i,m){
        int u , v ;
        ll c;
        cin >> u >> v >> c ;
        u-- ; v-- ;
        E[i] ={c,u,v,i};
    }
    sort(E,E+m,greater<TP>());
    rep(i,m){
        auto[c,u,v,id] = E[i];
        int lef = -1 , rig = k ;
        while(rig - lef > 1){
            int mid = (lef + rig) / 2 ;
            if(uf[mid].same(u,v)) lef = mid;
            else rig = mid;
        }
        if(rig == k) continue;
        uf[rig].unite(u,v);
        res[id] = rig + 1;
    }
    rep(i,m) cout << res[i] << endl;
}