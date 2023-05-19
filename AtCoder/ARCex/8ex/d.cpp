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

template<typename S , typename M> struct SegmentTree{
    private :
        int n , _n ;
        using FS = function<S(S,S)> ;
        using FA = function<S(S,M)> ;
        // fx: モノイド, fm: 作用子
        FS fx ;
        FA fa ;
        const S ex ;
        vector<S> dat ;

        inline S prod(int a , int b , int k , int l , int r) {
            if(r <= a || b <= l) return ex ;
            if(a <= l && r <= b) return dat[k] ;
            S lef = prod(a,b,2*k+1,l,(l+r)/2) ;
            S rig = prod(a,b,2*k+2,(l+r)/2,r) ;
            return fx(lef,rig) ;
        }

    public :
        SegmentTree(int n_ , FS fx_ , FA fa_ , S ex_ , S ee) : n() , fx(fx_) , fa(fa_) , ex(ex_) {
            _n = n_ ;
            n = 1 ;
            while(n_ > n) n *= 2 ;
            dat.resize(2 * n - 1,ee) ;
        }

        void set(int k , M x) {
            k += n - 1 ;
            dat[k] = fa(dat[k],x) ;
            while(k > 0) {
                k = (k - 1) / 2 ;
                dat[k] = fx(dat[2*k+1],dat[2*k+2]) ;
            }
        }

        S prod(int a , int b) { return prod(a,b,0,0,n) ; }
};

namespace monoid{
    ll inf = 1e16 ;

    struct S{
        ld a;
        ld b;
    };

    function<S(S,S)> fs = [](S x , S y) -> S {
        return S{
            x.a * y.a,
            y.a * x.b + y.b
        };
    };

    S es = {
        1,
        0
    };
    S ee = {
        1,
        0
    } ;

    struct M{
        ld a ;
        ld b ;
        bool operator == (M x) { return a == x.a && b == x.b; }
    };

    M em = {1,0};

    function<S(S,M)> fa = [](S x , M y) -> S {
        return S{
            y.a,
            y.b
        };
    };
} using namespace monoid;

ll n, m;
vector<tuple<ll,ld,ld>> X;

int main(){
    fast_input_output
    cin >> n >> m;
    if(m == 0){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    X.resize(m);
    vector<ll> vec;
    rep(i,m){
        ll p;
        ld a, b;
        cin >> p >> a >> b;
        p--;
        X[i] = {p,a,b};
        vec.push_back(p);
    }
    Compress<ll> C(vec);
    SegmentTree<S,M> segtree(m,fs,fa,es,ee);

    ld minval = 1e18, maxval = 1;
    rep(i,m){
        auto[p,a,b] = X[i];
        int idx = C[i];
        segtree.set(idx, {a,b});
        auto[x,y] = segtree.prod(0,m);
        chmin(minval,x+y);
        chmax(maxval,x+y);
    }
    cout << fixed << setprecision(25) << minval << endl;
    cout << fixed << setprecision(25) << maxval << endl;
}