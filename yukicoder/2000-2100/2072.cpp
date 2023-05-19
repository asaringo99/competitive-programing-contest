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
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数
        vector<int> value;

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            value.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
                value[i] = 0;
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
                value[x] = max(value[x],value[y]) + 1;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
                value[y] = max(value[x],value[y]) + 1;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                value[x] = max(value[x],value[y]) + 1;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
        int solve(int x) { return value[root(x)] ; }
};

int n, m ;
pair<int,int> E[202020];

int main(){
    fast_input_output
    cin >> n >> m ;
    UnionFind uf(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[i] = {a,b};
    }
    for(int i = m - 1 ; i >= 0 ; i--){
        auto [a, b] = E[i];
        uf.unite(a,b);
    }
    int res = 0;
    rep(i,n) chmax(res,uf.solve(i));
    cout << res << endl;
}