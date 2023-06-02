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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数
        vector<int> minval;
        vector<int> maxval;

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            minval.reserve(n);
            maxval.reserve(n);
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
                minval[i] = i;
                maxval[i] = i;
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
                chmin(minval[y],minval[x]);
                chmax(maxval[y],maxval[x]);
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                chmin(minval[x],minval[y]);
                chmax(maxval[x],maxval[y]);
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
        int minv(int x) { return minval[root(x)]; }
        int maxv(int x) { return maxval[root(x)]; }
};

vector<int> A;
vector<vector<int>> X;
vector<pair<int,int>> res;

void solve(){
    int n;
    cin >> n;
    UnionFind uf(n);
    A = vector<int>(n);
    rep(i,n) cin >> A[i];
    X = vector<vector<int>>(101010);
    rep(i,n) X[A[i]].push_back(i);
    set<int> st;
    for(int i = 100000; i > 0; i--){
        for(int u : X[i]) {
            st.insert(u);
            if(st.count(u+1)) uf.unite(u,u+1);
            if(st.count(u-1)) uf.unite(u,u-1);
        }
        int k = 0;
        while(k < n){
            auto it = st.lower_bound(k);
            if(it == st.end()) break;
            k = *it;
            res.push_back({uf.minv(k) + 1, uf.maxv(k) + 1});
            k = uf.maxv(k) + 1;
        }
    }
    cout << res.size() << endl;
    for(auto[a,b] : res) cout << a << " " << b << endl;
}

int main(){
    // fast_io
    solve();
}