#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T=ll> struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> rank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数
        vector<T> weight ; //重み(親の重みは0)

    public:
        UnionFind(int n){
            par.resize(n) ;
            rank.resize(n,0) ;
            volume.resize(n,1) ;
            edge.resize(n,0) ;
            weight.resize(n,0) ;
            for(int i = 0 ; i < n ; i++) par[i] = i ;
        }

        T potential(int x){
            root(x);
            return weight[x];
        }

        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x;
            int r = root(par[x]);
            weight[x] += weight[par[x]];
            return par[x] = r;
        }

        //xとyの属する集合を合併
        void unite(int x, int y, T w = 0){
            w += potential(x) - potential(y);

            x = root(x);
            y = root(y);
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(rank[x] < rank[y]){
                swap(x,y);
                w = -w;
            } 
            if(rank[x] == rank[y]) rank[x]++;
            par[y] = x;
            volume[x] += volume[y];
            edge[x] += edge[y] + 1;
            weight[y] = w;
        }

        bool same(int x , int y) { return root(x) == root(y); }
        int size(int x) { return volume[root(x)]; }
        int edge_num(int x) { return edge[root(x)]; }
        T diff(int x, int y){ return potential(y) - potential(x); }
};


int n, m;

int main(){
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m){
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        if(uf.same(l,r)){
            if(uf.diff(l,r) != d){
                pt("No");
                return 0;
            }
        }
        else uf.unite(l,r,d);
    }
    pt("Yes");
}