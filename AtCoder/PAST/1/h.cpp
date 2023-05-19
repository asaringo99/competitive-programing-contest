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

namespace monoid{
    struct S{ ll min; int size; };
    S e() { return S{(ll)1e18, 0}; }
    S op(S x , S y) { return S{ min(x.min, y.min), x.size + y.size }; }
    struct M{ ll a; };
    M id() { return M{0}; }
    S mapping(M x , S y) { return S{ x.a + y.min, y.size }; }
    M composition(M x, M y) { return M{ x.a + y.a }; }
    int target;
    auto f = [](S x) -> bool { return x.min < target; };
} using namespace monoid;


int n, q;

int main(){
    fast_io
    cin >> n;
    vector<ll> C(n);
    vector<S> E, O;
    rep(i,n) cin >> C[i];
    rep(i,n){
        if(i % 2 == 0) O.push_back({C[i],1});
        else E.push_back({C[i],1});
    }

    LazySegmentTree<S, op, e, M, mapping, composition, id> segtreeeve(E), segtreeodd(O);
    cin >> q;
    ll res = 0;
    rep(i,q){
        int t, x, a;
        cin >> t;
        if(t == 1){
            cin >> x >> a;
            x--;
            if(x % 2 == 0){
                if(segtreeodd.get(x/2).min >= a) {
                    segtreeodd.apply(x/2,{-a});
                    res += a;
                }
            }
            else{
                if(segtreeeve.get(x/2).min >= a) {
                    segtreeeve.apply(x/2,{-a});
                    res += a;
                }
            }
        }
        if(t == 2){
            cin >> a;
            if(segtreeodd.prod(0,(n+1)/2).min >= a) {
                segtreeodd.apply(0,(n+1)/2,{-a});
                res += (n + 1) / 2 * a;
            }
        }
        if(t == 3){
            cin >> a;
            if(segtreeodd.prod(0,(n+1)/2).min >= a && segtreeeve.prod(0,n/2).min >= a) {
                segtreeeve.apply(0,n/2,{-a});
                segtreeodd.apply(0,(n+1)/2,{-a});
                res += n * a;
            }
        }
        // cout << i << " " << res << endl;
    }
    cout << res << endl;
}