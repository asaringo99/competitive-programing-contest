#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
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
    struct S{ ld min;};
    S e() { return S{1e18}; }
    S op(S x , S y) { return S{min(x.min,y.min)}; }
    S mapping(S x , S y) { return S{y.min}; }
    int target;
    auto f = [](S x) -> bool { return x.min < target; };
} using namespace monoid;

void solve(){
    ll n, m;
    ld c;
    cin >> n >> m >> c;
    vector<ld> A(n), P(n-1);
    vector<ll> I(n+1);
    vector<pair<int,int>> X(m);
    rep(i,n) cin >> A[i];
    rep(i,n-1) cin >> P[i];
    rep(i,m){
        int a, b;
        cin >> a >> b;
        X[i] = {a-1,b-1};
        I[a-1]++;
        I[b-1]--;
    }
    vector<ld> R(n,0);
    SegmentTree<S, op, mapping, e> segtree(n);
    int sum = I[0];
    rrep(i,1,n){
        ld e = (ld)(A[i] - A[i-1]) * sum * (100 - P[i-1]) / 200 + (ld)(-c) * sum * P[i-1] / 100;
        cout << e << " ";
        R[i] = R[i-1] + e;
        segtree.apply(i,{R[i]});
        sum += I[i];
    }
    cout << endl;
    rep(i,n) cout << R[i] << " "; cout << endl;
    ld res = 0;
    rrep(i,1,n){
        ld val = R[i] - segtree.prod(0,i).min;
        chmax(res,val);
    }
    cout << fixed << setprecision(25) << res << endl;
}

int main(){
    fast_io
    solve();
}