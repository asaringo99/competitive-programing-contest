#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

// 座標圧縮
template<typename T=int> struct Compress{
    private:
        vector<int> vec ; // 元の値の座標圧縮後の値
        unordered_map<T,int> mp ; // 元の値 -> 変換された値
        unordered_map<int,T> np ; // 変換された値 -> 元の値

        void build(vector<T> A){
            int n = A.size() ;
            vector<T> B(n) ;
            for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
            vec.resize(n) ;
            sort(A.begin(),A.end()) ;
            for(int i = 0 ; i < n ; i++){
                auto it = lower_bound(A.begin(),A.end(),B[i]) ;
                int id = it - A.begin() ;
                vec[i] = id ;
                mp[B[i]] = id;
                np[id] = B[i] ;
            }
        }

    public:
        Compress(){}
        Compress(vector<T> A) { build(A); }
        size_t size() {return vec.size() ; }
        // 元の値 -> 変換された値
        inline int encrypt(T i) { return mp[i] ; }
        // 変換された値 -> 元の値
        inline T decrypt(int i) { return np[i] ; }
        vector<int> compress() { return vec; }
        vector<int> compress(vector<T> A) { build(A); return vec; }
        inline int operator [] (int i) { return vec[i] ; }
};

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
    struct S{ ll sum; ll cnt;};
    S e() { return S{0, 0}; }
    S op(S x , S y) { return S{ x.sum + y.sum, x.cnt + y.cnt}; }
    S mapping(S x , S y) { return S{ x.sum + y.sum * y.cnt, x.cnt + y.cnt}; }
    int target;
    auto f = [](S x) -> bool { return x.cnt < target; };
} using namespace monoid;

int n, q;

ll A[202020], B[202020];
vector<int> V;

int main(){
    // fast_input_output
    cin >> n;
    rep(i,n) cin >> A[i] >> B[i], V.push_back(A[i]);
    cin >> q;
    vector<vector<int>> query;
    SegmentTree<S, op, mapping, e> segtree(n+q);
    rep(i,q){
        int t, x, y;
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            query.push_back({t,x,y});
            V.push_back(y);
        }
        if(t == 2){
            cin >> x >> y;
            query.push_back({t,x,y});
        }
        if(t == 3){
            cin >> x;
            query.push_back({t,x});
        }
    }
    Compress<int> C(V);
    rep(i,n){
        segtree.apply(C.encrypt(A[i]),{A[i], B[i]});
    }
    rep(i,q){
        auto vec = query[i];
        int t = vec[0];
        if(t == 1){
            int x = vec[1], y = vec[2];
            x--;
            ll a = A[x], b = B[x];
            segtree.apply(C.encrypt(a), {a, -b});
            segtree.apply(C.encrypt(y), {y, b});
            A[x] = y;
        }
        if(t == 2){
            int x = vec[1], y = vec[2];
            x--;
            ll a = A[x], b = B[x];
            segtree.apply(C.encrypt(a), {a, -b});
            segtree.apply(C.encrypt(a), {a, y});
            B[x] = y;
        }
        if(t == 3){
            int x = vec[1];
            if(segtree.all_prod().cnt < x){
                cout << -1 << endl;
                continue;
            }
            target = x;
            int lef = segtree.min_left<f>(n+q);
            S m = segtree.prod(lef,n+q);
            ll res = m.sum;
            if(lef > 0) res += C.decrypt(lef-1) * (x - m.cnt);
            cout << res << endl;
        }
    }
}