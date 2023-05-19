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

// template<typename S, S (*op)(S, S), S (*mapping)(S, S), S (*e)()> struct SegmentTree{
//     private:
//         int n_, n, log;
//         vector<S> node;

//         void init_(S ev) { node = {}; node.resize(2*n-1,ev); }
        
//         void build(vector<S> V){
//             n = 1;
//             log = 0;
//             while(n < n_) n *= 2, log++;
//             node.resize(2*n-1,e());
//             for(int i = 0; i < n_; i++) node[n-1+i] = V[i];
//             for(int i = n - 2; i >= 0; i--) node[i] = op(node[2*i+1], node[2*i+2]);
//         }
        
//         void apply_(int k, S x){
//             k += n - 1;
//             node[k] = mapping(node[k],x);
//             while(k > 0){
//                 k = (k - 1) / 2;
//                 node[k] = op(node[2*k+1], node[2*k+2]);
//             }
//         }

//         S get_(int k) const { return node[k+n-1]; }

//         S prod_(int l, int r) const {
//             S lval = e(), rval = e();
//             l += n - 1;
//             r += n - 1;

//             while(l < r){
//                 if(!(l & 1)) lval = op(lval, node[l++]);
//                 if(!(r & 1)) rval = op(rval, node[--r]);
//                 l >>= 1;
//                 r >>= 1;
//             }
//             return op(lval, rval);
//         }

//         S all_prod_() const { return node[0]; }

//         template<bool (*f)(S)> int max_right_(int l) const {
//             return max_right_(l, [](S x) { return f(x); });
//         }

//         template<typename F> int max_right_(int l, F f) const {

//             l += n;
//             S sval = e();

//             do {
//                 while(l % 2 == 0) l >>= 1;
//                 if(!f(op(sval, node[l-1]))) {
//                     while(l < n){
//                         l = 2 * l;
//                         if(f(op(sval, node[l-1]))) {
//                             sval = op(sval, node[l-1]);
//                             l++;
//                         }
//                     }
//                     return l - n;
//                 }
//                 sval = op(sval, node[l-1]);
//                 l++;
//             } while ((l & -l) != l);

//             return n_;
//         }

//         template<bool (*f)(S)> int min_left_(int r) const {
//             return min_left_(r, [](S x) { return f(x); });
//         }

//         template<typename F> int min_left_(int r, F f) const {
//             r += n;
//             S sval = e();
//             do {
//                 r--;
//                 while(r > 1 && r & 1) r >>= 1;
//                 if(!f(op(sval, node[r-1]))) {
//                     while(r < n) {
//                         r = 2*r+1;
//                         if(f(op(sval, node[r-1]))) {
//                             sval = op(sval,node[r-1]);
//                             r--;
//                         }
//                     }
//                     return r + 1 - n;
//                 }
//                 sval = op(sval, node[r-1]);
//             } while((r & -r) != r);

//             return 0;
//         }

//     public:
//         SegmentTree(int n): SegmentTree(vector<S>(n, e())) {}
//         SegmentTree(const vector<S>& V): n_((int)V.size()) { build(V); }
//         void init(S ev) { init_(ev); }
//         void apply(int k, S x) { apply_(k, x); }
//         S get(int k) const { return get_(k); }
//         S prod(int l, int r) const { return prod_(l, r); }
//         S all_prod() const { return all_prod_(); }
//         template<bool (*f)(S)> int max_right(int l) const { return max_right_<f>(l); }
//         template<bool (*f)(S)> int min_left(int  r) const { return min_left_<f>(r); }

// };

// namespace monoid{
//     struct S{ pair<int,int> val;};
//     S e() { return S{{0,1e9}}; }
//     S op(S x , S y) { return S{min(x.val, y.val)}; }
//     S mapping(S x , S y) { return y; }
//     // int target;
//     // auto f = [](S x) -> bool { return x.sum < target; };
// } using namespace monoid;

template<typename T>
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,{1e9,1e9}) ;
    }
    void update(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return {1e9,1e9} ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};


int n, m;
int A[202020];
int T[202020];
vector<pair<int,int>> V;
vector<int> X[202020];
bool used[202020];

int main(){
    // fast_io
    cin >> n >> m;
    rep(i,n) cin >> A[i], A[i]--;
    SegmentTree<pair<int,int>> segtree(n);
    rep(i,n) {
        segtree.update(i,{A[i],i});
    }
    rep(i,n){
        chmax(T[A[i]],i);
        X[A[i]].push_back(i);
    }
    rep(i,m){
        V.push_back({T[i],i});
    }
    sort(all(V));
    // for(auto[v,id] : V){
    //     cout << v << " " << id << endl;
    // }
    int lef = 0;
    int i = 0;
    vector<int> res;
    while(i < V.size()){
        // cout << i << endl;
        auto[r, val] = V[i];
        if(used[val]) {
            i++;
            continue;
        }
        int rig = r+1;
        while(lef < rig){
            // cout << lef << " " << rig << endl;
            auto[v, id] = segtree.query(lef, rig);
            if(v > val) break;
            // cout << v << " " << id << endl;
            // return 0;
            res.push_back(v+1);
            lef = id+1;
            for(int tim : X[v]) segtree.update(tim,{1e9,1e9});
            used[v] = true;
        }
        i++;
    }
    for(int u : res) cout << u << " "; cout << endl;
}