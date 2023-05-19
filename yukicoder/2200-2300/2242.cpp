#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

// function               : return              : description
// -----------------------------------------------------
// Compress()             : void          : コンストラクタ
// Compress(vector<ll> A) : void          : コンストラクタ, 座圧する
// encrypt(ll v)          : int           : 元の値 -> 座圧後の値
// decrypt(int v)         : ll            : 座圧後の値 -> 元の値
// compress()             : vector<int>   : 座圧後の値
// operator[i]            : int           : 座圧後の値の vector にアクセスすることが可能

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
    struct S{ll max; int id;};
    S e() { return S{(ll)-2e9, -1}; }
    S op(S x , S y) {
        if(x.max > y.max) return x;
        else return y;
    }
    S mapping(S x , S y) { return y;}
    int target;
    auto f = [](S x) -> bool { return x.max <= target; };
} using namespace monoid;


int n;
int q;
ll H[202020];
ll T[202020];

struct Doubling {
    private:
        const ll INF = LLONG_MAX ;

        int n ;
        vector<vector<int>> dp ;
        vector<vector<ll>> S ;

        void init(vector<int> A_ , vector<ll> T) {
            n = A_.size() ;
            dp.resize(60,vector<int>(n)) ;
            S.resize(60,vector<ll>(n)) ;
            rep(i,n){
                dp[0][i] = A_[i] ;
                S[0][i] = T[i] ;
            }
        }

        void build_(int count = 59){
            rep(i,count) {
                rep(j,n) {
                    dp[i+1][j] = dp[i][dp[i][j]] ;
                    if(INF - S[i][j] <= S[i][dp[i][j]]) S[i+1][j] = INF ;
                    else S[i+1][j] = S[i][j] + S[i][dp[i][j]] ;
                }
            }
        }

        int get_index_(int v , ll k) {
            int cnt = 0 ;
            while(k > 0){
                if(k & 1) v = dp[cnt][v] ;
                cnt++ ;
                k >>= 1 ;
            }
            return v ;
        }

        ll get_sum_(int v , ll k) {
            ll sum = 0 ;
            int cnt = 0 ;
            while(k > 0){
                if(k & 1) {
                    if(INF - sum <= S[cnt][v]) sum = INF ;
                    else sum += S[cnt][v] ;
                    v = dp[cnt][v] ;
                }
                cnt++ ;
                k >>= 1 ;
            }
            return sum ;
        }


    public:
        // A[i] = j : i が j に遷移する
        // T[i] = x : i が j に遷移する時に得る個数(通りの数)が x である
        Doubling(vector<int> A_ , vector<ll> T = vector<ll>(202020,0)){ init(A_,T) ; }

        void build() { build_() ; }
        int get_index(int v , ll k) { return get_index_(v,k) ; }
        int get_next_moving_index(int v) { return dp[0][v] ; }
        ll get_sum(int v , ll k) { return get_sum_(v,k) ; }
        ll get_next_moving_sum(int v) { return S[0][v] ; }
        vector<vector<int>> get_table() { return dp; }
};

int main(){
    fast_input_output
    cin >> n;
    vector<pair<int,int>> X;
    rep(i,n) cin >> H[i];
    rep(i,n) cin >> T[i], X.push_back({T[i],i});
    SegmentTree<S, op, mapping, e> segtree(n);
    sort(all(X));
    vector<int> D(n);
    for(int i = n - 1; i >= 0; i--){
        auto[t, id] = X[i];
        ll minval = 1e18;
        int gid = -1;
        if(i < n - 1) {
            S s = segtree.prod(i+1,i+2);
            minval = s.max;
            gid = s.id;
        }
        int h = H[id];
        // cout << gid << " " << minval << " ";
        if(minval > h){
            segtree.apply(i,{h,i});
        }
        else{
            segtree.apply(i,{minval,gid});
        }
        target = t;
        int maxrig = segtree.max_right<f>(i+1);
        // cout << maxrig << " " << t << " ";
        auto[nt,nid] = X[maxrig-1];
        // cout << id << " " << nid << endl;
        D[id] = nid;
    }
    Doubling dbg(D);
    dbg.build();
    auto table = dbg.get_table();

    cin >> q;
    rep(i,q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(T[a] >= H[b]){
            cout << 1 << endl;
            continue;
        }
        int res = 0;
        for(int i = 20; i >= 0; i--){
            // cout << "p : " << T[table[i][a]] << " " << table[i][a] << endl;
            if(T[table[i][a]] >= H[b]) continue;
            a = table[i][a];
            // cout << "h" << endl;
            res += 1 << i;
        }
        if(res > n) res = -1;
        else res += 2;
        cout << res << endl;
    }
}