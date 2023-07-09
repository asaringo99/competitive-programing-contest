#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll;
typedef long double ld;
#define chmin(a,b) a = min(a,b);
#define chmax(a,b) a = max(a,b);
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl;
#define debug(a) cout << #a << " " << a << endl;
#define all(a) a.begin(), a.end()
#define endl "\n";
#define v1(n,a) vector<ll>(n,a)
#define v2(n,m,a) vector<vector<ll>>(n,v1(m,a))
#define v3(n,m,k,a) vector<vector<vector<ll>>>(n,v2(m,k,a))
#define v4(n,m,k,l,a) vector<vector<vector<vector<ll>>>>(n,v3(m,k,l,a))
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const multiset<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}


template<typename S, S (*op)(S, S), S (*mapping)(S, S), S (*e)()> struct SegmentTree{
    private:
        int n_, n, log;
        vector<S> node;

        void init_(S ev) { node = {}; node.resize(2*n-1,ev); }
        
        void build(vector<S> V){
            n = 1;
            log = 0;
            while(n < n_) n *= 2, log++;
            node.resize(2*n,e());
            for(int i = 0; i < n_; i++) node[n+i] = V[i];
            for(int i = n - 1; i >= 1; i--) node[i] = op(node[2*i], node[2*i+1]);
        }
        
        void apply_(int k, S x){
            k += n ;
            node[k] = mapping(node[k],x);
            while(k > 0){
                k = k / 2;
                node[k] = op(node[2*k], node[2*k+1]);
            }
        }

        S get_(int k) const { return node[k+n]; }

        S prod_(int l, int r) const {
            S lval = e(), rval = e();
            l += n;
            r += n;

            while(l < r){
                if(l & 1) lval = op(lval, node[l++]);
                if(r & 1) rval = op(node[--r], rval);
                l >>= 1;
                r >>= 1;
            }
            return op(lval, rval);
        }

        S all_prod_() const { return node[1]; }

        template<bool (*f)(S)> int max_right_(int l) const {
            return max_right_(l, [](S x) { return f(x); });
        }

        template<typename F> int max_right_(int l, F f) const {

            l += n;
            S sval = e();

            do {
                while(l % 2 == 0) l >>= 1;
                if(!f(op(sval, node[l]))) {
                    while(l < n){
                        l = 2 * l;
                        if(f(op(sval, node[l]))) {
                            sval = op(sval, node[l]);
                            l++;
                        }
                    }
                    return l - n;
                }
                sval = op(sval, node[l]);
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
                if(!f(op(node[r],sval))) {
                    while(r < n) {
                        r = 2*r+1;
                        if(f(op(node[r],sval))) {
                            sval = op(node[r],sval);
                            r--;
                        }
                    }
                    return r + 1 - n;
                }
                sval = op(node[r],sval);
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
    struct S{ ll sum;};
    S e() { return S{0}; }
    S op(S x , S y) { return S{x.sum + y.sum}; }
    S mapping(S x , S y) { return S{x.sum + y.sum}; }
    int target;
    auto f = [](S x) -> bool { return x.sum < target; };
} using namespace monoid;

// SegmentTree<S, op, mapping, e> segtree(n)

int L[202020], R[202020];

void solve(){
    int n, m, q;
    string str;
    cin >> n >> m >> q >> str;
    int o = 0;
    rep(i,n) if(str[i] == '1') o++;
    rep(i,m) cin >> L[i] >> R[i];
    vector<int> A(n), mp(n,-1), I, C;
    rep(i,n) A[i] = str[i] - '0';
    set<int> used;
    rep(i,n) used.insert(i);
    rep(i,m){
        int l = L[i], r = R[i];
        l--;
        r--;
        int x = l;
        while(x <= r){
            auto it = used.lower_bound(x);
            if(it == used.end()) break;
            x = *it;
            if(x > r) break;
            mp[x] = I.size();
            I.push_back(x);
            C.push_back(A[x]);
            used.erase(it);
        }
    }
    int sz = I.size();
    SegmentTree<int> segtree(sz);
    rep(i,sz) segtree.update(i, C[i] != 1);
    rep(i,q){
        int v;
        cin >> v;
        v--;
        if(mp[v] != -1) {
            C[mp[v]] ^= 1;
            segtree.update(mp[v], C[mp[v]] != 1);
        }
        if(A[v] == 0) o++;
        if(A[v] == 1) o--;
        A[v] ^= 1;
        cout << segtree.query(0,o) << endl;
    }
}

int main(){
    fast_io
    int t = 1;
    // cin >> t;
    rep(i,t) solve();
}