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

template<typename S, S (*op)(S, S), S (*e)(), typename M, S (*mapping)(M, S), M (*composition)(M, M), M (*id)()> struct LazySegmentTree{
    private:
        int size, log, _n;
        vector<S> d;
        vector<M> lz;

        void init_(S ev, M idv, int size) { d = {}; lz = {}; d.resize(2*size,ev); lz.resize(size,idv); }
        
        void build(vector<S> V){
            size = 1;
            log = 0;
            while(size < _n) size *= 2, log++;
            d = std::vector<S>(2 * size, e());
            lz = std::vector<M>(size, id());
            for (int i = 0; i < _n; i++) d[size + i] = V[i];
            for (int i = size - 1; i >= 1; i--) update(i);
        }

        // 与えられたMの値をapplyし、遅延配列にcompositionする
        void all_apply(int k, M f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }

        // 自身の遅延配列を子要素に振り分け、自身の遅延配列をMの単位元にする
        void push(int k) {
            all_apply(2 * k, lz[k]);
            all_apply(2 * k + 1, lz[k]);
            lz[k] = id();
        }

        // 親のノード = 子ノード同士のop演算結果となる
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

        void set_(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get_(int p) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }
        
        void apply_(int p, M f) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        void apply_(int l, int r, M f) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return;


            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                // l, rが葉から登っていく際に、現在自分がいるノードの遅延配列をmappingする必要がある。
                // しかし、遅延セグメント木のアルゴリズムの関係上、本来格納されているはずの遅延配列上の値が自分のノードにはなく、親がもっていることがある。
                // そのため、親から前もって自身のノードが持べき遅延配列の値をもらっておく必要がある。
                // よって、このapply_関数上では、l, rの繊維先ノードで必要となる遅延配列の値（必要となる値のみ）を前もって子ノードに振り分けておく
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }

            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }


        S prod_(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return e();

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }

            return op(sml, smr);
        }

        S all_prod_() { return d[1]; }

        template <bool (*g)(S)> int max_right_(int l) {
            return max_right_(l, [](S x) { return g(x); });
        }
        template <class G> int max_right_(int l, G g) {
            assert(0 <= l && l <= _n);
            assert(g(e()));
            if (l == _n) return _n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = (2 * l);
                        if (g(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }

        template <bool (*g)(S)> int min_left_(int r) {
            return min_left_(r, [](S x) { return g(x); });
        }
        template <class G> int min_left_(int r, G g) {
            assert(0 <= r && r <= _n);
            assert(g(e()));
            if (r == 0) return 0;
            r += size;
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(op(d[r], sm))) {
                    while (r < size) {
                        push(r);
                        r = (2 * r + 1);
                        if (g(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }

    public:
        LazySegmentTree(int n): LazySegmentTree(vector<S>(n, e())) {}
        LazySegmentTree(const vector<S>& V): _n((int)V.size()) { build(V); }
        void init(S ev = e(), M idv = id()) { init_(ev, idv); }
        void set(int p, S x) { set_(p,x); }
        void apply(int k, M x) { apply_(k, x); }
        void apply(int l, int r, M x) { apply_(l, r, x); }
        S get(int k) { return get_(k); }
        S prod(int l, int r) { return prod_(l, r); }
        S all_prod() { return all_prod_(); }
        template<bool (*f)(S)> int max_right(int l) { return max_right_<f>(l); }
        template<bool (*f)(S)> int min_left(int  r) { return min_left_<f>(r); }
};

struct HeavyLightDecomposition{

    HeavyLightDecomposition(int n_): n(n_){
        G.resize(n);
        size.resize(n);
        in.resize(n);
        out.resize(n);
        head.resize(n);
        rev.resize(n);
        par.resize(n);
    }

    int n;
    vector<vector<int>> G;
    // size: subtree[v]の子の数
    // in[v]  : オイラーツアーでvを訪れた時間
    // out[v] : オイラーツアーでvから親に戻った時間
    // head[v]: heavy部分の最も親なノード
    // rev[t] : t時点についてt-1時点に訪れたノード
    // par[v] : ノードvの親ノード
    vector<int> size, in, out, head, rev, par;

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void dfs_size(int v, int prev){
        par[v] = prev;
        size[v] = 1;
        if(G[v].size() > 0 && G[v][0] == prev) swap(G[v][0], G[v].back());
        for(int &to: G[v]){
            if(to == prev) continue;
            dfs_size(to, v);
            size[v] += size[to];
            if(size[G[v][0]] < size[to]) swap(G[v][0], to);
        }
    }

    void dfs_hld(int v, int prev, int &times){
        in[v] = times++;
        rev[in[v]] = v;
        for(int &to: G[v]){
            if(to == prev) continue;
            head[to] = (G[v][0] == to ? head[v] : to);
            dfs_hld(to, v, times);
        }
        out[v] = times;
    }

    void build(){
        dfs_size(0, -1);
        int t = 0;
        dfs_hld(0, -1, t);
    }

    int la(int v, int k){
        while(1){
            int u = head[v];
            if(in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v){
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
        }
    }

    template<typename S, typename Q, typename F>
    S query(int u, int v, const S &e, const Q &op, const F &merge, bool edge = false){
        S l = e, r = e;
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) {
                swap(u, v);
                swap(l, r);
            }
            if(head[u] == head[v]) break;
            l = merge(op(in[head[v]], in[v] + 1), l);
        }
        return merge(merge(op(in[u] + edge, in[v] + 1), l), r);
    }

    template<typename Q>
    void apply(int u, int v, const Q &f, bool edge = false){
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            f(in[head[v]], in[v] + 1);
        }
        f(in[u] + edge, in[v] + 1);
    }
};

// function               : return              : description
// -----------------------------------------------------
// build()                         : void                : ビルドする
// la(v, k)                        : int                 : vのk個祖先を求める
// lca(v, u)                       : int                 : v, u のlcaを求める
// query(v, u, e, op, merge, edge) : monoid::S           : v から u までのパスに対する取得クエリを行う
// apply(v, u, f, edge)            : void                : v から u までのパスに対する更新クエリを行う
// *注意* 取り敢えず全てをコピペすることを奨励

// 区間加算区間最大値
namespace monoid{
    struct S{ ll val; int size; };
    ll operate(ll x, ll y) { return max(x, y); }
    S e() { return S{(ll)-1e18, 0}; }
    S op(S x , S y) { return S{ operate(x.val, y.val), x.size + y.size }; }
    struct M{ ll a; };
    M id() { return M{(ll)-1e18}; }
    S mapping(M x , S y) {
        if(x.a == id().a) return y;
        return S{ x.a, y.size };
    }
    M composition(M x, M y) {
        if(x.a == id().a) return y;
        return x;
    }
    int target;
    auto binary_search = [](S x) -> bool { return x.val < target; };
} using namespace monoid;

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
                volume[i] = 1 ;
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

int n, m;

int main(){
    fast_io
    cin >> n >> m;
    vector<tuple<ll,int,int>> V;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        V.push_back({c,a,b});
    }
    auto U = V;
    sort(all(U));
    UnionFind uf(n);
    vector<vector<pair<int,ll>>> G(n);
    ll res = 0;
    rep(i,m){
        auto [val,a,b] = U[i];
        if(uf.same(a,b)) continue;
        uf.unite(a,b);
        G[a].push_back({b,val});
        G[b].push_back({a,val});
        res += val;
    }
    vector<S> vec(n,{0,1});
    LazySegmentTree<S, op, e, M, mapping, composition, id> segtree(vec);
    HeavyLightDecomposition HLD(n);
    rep(v,n){
        for(auto[u,cost] : G[v]){
            if(v < u) HLD.add_edge(u,v);
        }
    }
    HLD.build();
    rep(v,n){
        for(auto[u,cost] : G[v]){
            M m = {cost};
            auto f = [&](int v, int u) { segtree.apply(v,u,m); };
            HLD.apply(u,v,f,true);
        }
    }
    rep(i,m){
        auto[cost,v,u] = V[i];
        auto calc = [&](int v, int u) { return segtree.prod(v, u); };
        auto merge = [](S x, S y) { return op(x, y); };
        cout << res - HLD.query(u,v,e(),calc,merge,true).val + cost << endl;
    }
}