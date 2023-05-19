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

template<typename S, S (*op)(S, S), S (*mapping)(S, S), S (*e)()> struct SegmentTree{
    private:
        int n_, n, log;
        vector<S> node;

        void init_(S ev) { node = {}; node.resize(2*n-1,ev); }
        
        void build(vector<S> V){
            n = 1;
            log = 0;
            while(n < n_) n *= 2, log++;
            node.resize(2*n-1,e());
            for(int i = 0; i < n_; i++) node[n-1+i] = V[i];
            for(int i = n - 2; i >= 0; i--) node[i] = op(node[2*i+1], node[2*i+2]);
        }
        
        void apply_(int k, S x){
            k += n - 1;
            node[k] = mapping(node[k],x);
            while(k > 0){
                k = (k - 1) / 2;
                node[k] = op(node[2*k+1], node[2*k+2]);
            }
        }

        S get_(int k) const { return node[k+n-1]; }

        S prod_(int l, int r) const {
            S lval = e(), rval = e();
            l += n - 1;
            r += n - 1;

            while(l < r){
                if(!(l & 1)) lval = op(lval, node[l++]);
                if(!(r & 1)) rval = op(rval, node[--r]);
                l >>= 1;
                r >>= 1;
            }
            return op(lval, rval);
        }

        S all_prod_() const { return node[0]; }

        template<bool (*f)(S)> int max_right_(int l) const {
            return max_right_(l, [](S x) { return f(x); });
        }

        template<typename F> int max_right_(int l, F f) const {

            l += n;
            S sval = e();

            do {
                while(l % 2 == 0) l >>= 1;
                if(!f(op(sval, node[l-1]))) {
                    while(l < n){
                        l = 2 * l;
                        if(f(op(sval, node[l-1]))) {
                            sval = op(sval, node[l-1]);
                            l++;
                        }
                    }
                    return l - n;
                }
                sval = op(sval, node[l-1]);
                l++;
            } while ((l & -l) != l);

            return n_;
        }

        template<bool (*f)(S)> int min_left_(int r) const {
            return min_left_(r, [](S x) { return f(x); });
        }

        template<typename F> int min_left_(int r, F f) const {
            r += n;
            S sval = e();
            do {
                r--;
                while(r > 1 && r & 1) r >>= 1;
                if(!f(op(sval, node[r-1]))) {
                    while(r < n) {
                        r = 2*r+1;
                        if(f(op(sval, node[r-1]))) {
                            sval = op(sval,node[r-1]);
                            r--;
                        }
                    }
                    return r + 1 - n;
                }
                sval = op(sval, node[r-1]);
            } while((r & -r) != r);

            return 0;
        }

    public:
        SegmentTree(int n): SegmentTree(vector<S>(n, e())) {}
        SegmentTree(const vector<S>& V): n_((int)V.size()) { build(V); }
        void init(S ev) { init_(ev); }
        void apply(int k, S x) { apply_(k, x); }
        S get(int k) const { return get_(k); }
        S prod(int l, int r) const { return prod_(l, r); }
        S all_prod() const { return all_prod_(); }
        template<bool (*f)(S)> int max_right(int l) const { return max_right_<f>(l); }
        template<bool (*f)(S)> int min_left(int  r) const { return min_left_<f>(r); }

};

namespace monoid{
    struct S{ pair<ll,ll> val; };
    S e() { return S{{(ll)1e18,-1}}; }
    S op(S x , S y) { return S{min(x.val, y.val)}; }
    S mapping(S x , S y) { return y; }
} using namespace monoid;


ll n, k, d;
map<int,vector<int>> mp;
ll A[202020];

int main(){
    fast_io
    cin >> n >> k >> d;
    SegmentTree<S, op, mapping, e> segtree(n);
    rep(i,n) cin >> A[i], segtree.apply(i,{{A[i],i}});
    vector<int> res;
    int id = 0;
    while(k > 0){
        int r = (k - 1) * d;
        if(id >= n - r){
            cout << -1 << endl;
            return 0;
        }
        auto it = segtree.prod(id,n-r);
        id = it.val.second + d;
        res.push_back(it.val.first);
        k--;
    }
    for(int u : res) cout << u << " "; cout << endl;
}