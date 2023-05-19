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
typedef tuple<ll,int,int> TP ;
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
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                if(i < n - 2) volume[i] = 1 ;
                edge[i] = 0 ;
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
};


int n, m ;
P X[202020];
P Y[202020];
vector<int> G[202020];
TP E[202020];

ll f(bool a, bool b){
    int i = 0, j = 0, k = 0;
    UnionFind uf(n+2);
    ll res = 0;
    if(a){
        res += X[0].first + X[1].first;
        uf.unite(X[0].second,n);
        uf.unite(X[1].second,n);
        i+=2;
    }
    if(b){
        res += Y[0].first + Y[1].first;
        uf.unite(Y[0].second,n+1);
        uf.unite(Y[1].second,n+1);
        j+=2;
    }
    while(i < n && j < n && k < n){
        ll aval = 1e16, bval = 1e16, cval = 1e16;
        int na, nb, nu, nv;
        if(i < n) tie(aval, na) = X[i];
        if(j < n) tie(bval,nb) = Y[j];
        if(k < m) tie(cval,nu,nv) = E[k];
        cout << aval << " " << bval << " " << cval << endl;
        if(a && aval <= bval && aval <= cval){
            i++;
            if(uf.same(na,n)) continue;;
            uf.unite(na,n);
            res += aval;
        }
        else if(b && bval <= aval && bval <= cval){
            j++;
            if(uf.same(nb,n+1)) continue;;
            uf.unite(nb,n+1);
            res += bval;
        }
        else{
            k++;
            if(uf.same(nv,nu)) continue;
            uf.unite(nv,nu);
            res += cval;
        }
    }
    return res;
}

int main(){
    fast_input_output
    cin >> n >> m ;
    UnionFind uf(n+2);
    rep(i,n) {
        int x;
        cin >> x;
        X[i] = {x,i};
    }
    rep(i,n) {
        int x;
        cin >> x;
        Y[i] = {x,i};
    }
    rep(i,m){
        int u , v, c ;
        cin >> u >> v >> c ;
        u-- ; v-- ;
        E[i] = {c,u,v};
    }
    sort(E,E+m);
    sort(X,X+n);
    sort(Y,Y+n);
    int a = 0, b = 0, c = 0;
    int ca = 0, cb = 0, cc = 0;
    ll res = 1e18;
    chmin(res,f(0,0));
    chmin(res,f(0,1));
    chmin(res,f(1,0));
    chmin(res,f(1,1));
    cout << res << endl;
}