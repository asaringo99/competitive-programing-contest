#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(long long i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(long long i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

const modint t = 2 ;
const modint inv = t.inverse() ;

template<typename S , typename M>
struct LazySegmentTree{
    private :
        int n , _n ;
        using FS = function<S(S,S)> ;
        using FM = function<M(M,M)> ;
        using FA = function<S(S,M)> ;
        FS fs ;
        FM fm ;
        FA fa ;
        S es ;
        M em ;
        vector<S> dat ;
        vector<M> lazy ;
        
        // 各セグメントに左端値, 右端値を持たせる
        void build(){
            int id = 0 ;
            for(int i = n ; i > 0 ; i = i / 2){
                for(int j = 0 ; j < n ; j += i){
                    dat[id].lef = j ;
                    dat[id].rig = j + i ;
                    id++ ;
                }
            }
        }
        void eval(int k , int l , int r){
            if(lazy[k] == em) return ;
            modint len = (r - l) / 2 ;
            if(k < n - 1) {
                lazy[2 * k + 1] = fm(lazy[2 * k + 1] , {lazy[k].a,lazy[k].b}) ;
                lazy[2 * k + 2] = fm(lazy[2 * k + 2] , {lazy[k].a,lazy[k].a*len+lazy[k].b}) ;
            }
            dat[k] = fa(dat[k],lazy[k]) ;
            lazy[k] = em ;
        }
        void apply(int a , int b , int k , int l , int r , M x){
            eval(k,l,r) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                lazy[k] = fm(lazy[k],{x.a,x.a*(l-a)+x.b}) ;
                eval(k,l,r) ;
                return ;
            }
            apply(a,b,2*k+1,l,(l+r)/2,x) ;
            apply(a,b,2*k+2,(l+r)/2,r,x) ;
            dat[k] = fs(dat[2*k+1],dat[2*k+2]) ;
        }
        S prod(int a , int b , int k , int l , int r) {
            eval(k,l,r) ;
            if(r <= a || b <= l) return es ;
            if(a <= l && r <= b) return dat[k] ;
            S lef = prod(a,b,2*k+1,l,(l+r)/2) ;
            S rig = prod(a,b,2*k+2,(l+r)/2,r) ;
            return fs(lef,rig) ;
        }
    
    public :
        LazySegmentTree(int n_ , FS fs_ , S es_ , S ee_ , FM fm_ , M em_ , FA fa_) : fs(fs_) , fm(fm_) , fa(fa_) , es(es_) , em(em_) {
            _n = n_ ;
            n = 1 ;
            while(n_ > n) n *= 2 ;
            dat.resize(2 * n - 1,ee_) ;
            lazy.resize(2 * n - 1,em) ;
            build() ;
        }
        void apply(int a , int b , M x) { apply(a,b,0,0,n,x) ; }
        S prod(int a , int b) { return prod(a,b,0,0,n) ; }
};

namespace monoid{
    ll linf = 1e16 ;
    modint inf = 1e8 ;

    // モノイド
    struct S{
        modint sum ;
        modint lef , rig ;
    };

    // S*S->Sにおける演算の定義
    function<S(S,S)> fs = [](S x , S y) -> S {
        return S{
            x.sum + y.sum,
            x.lef,
            y.rig
        };
    };
    
    // Sの単位元
    S es = {0,inf,-inf} ;

    // Sの初期化単位元
    S ee = {0,0,0} ;

    // 作用モノイド
    struct M{
        modint a , b ;
        bool operator == (M x) { return a == x.a && b == x.b ; }
    };

    // M*M->Mにおける演算の定義1
    function<M(M,M)> fm = [](M x , M y) -> M {
        return M{
            x.a + y.a,
            x.b + y.b
        };
    };

    // Mの単位元
    M em = {0,0} ;

    // S*M->Sにおける演算の定義
    function<S(S,M)> fa = [](S x , M y) -> S {
        modint len = (x.rig - x.lef) ;
        modint lef = x.lef ;
        return S{
            x.sum + len * (len - 1) / 2 * y.a + len * y.b ,
            x.lef,
            x.rig,
        };
    };
};
using namespace monoid ;

// monoid
// S    : sum(区間和) , lef(区間左端値), rig(区間右端値) 
// M    : (a,b) -> ax + b のモノイド
// apply: 区間等差数列加算
// prod : sum(区間和), min(区間最小値), max(区間最大値)

// verified: https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2020Day1/problems/B

ll n , q ;
modint A[202020] ;

int main() {
    fast_input_output
    cin >> n >> q ;
    LazySegmentTree<S,M> segtree(n,fs,es,ee,fm,em,fa) ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        segtree.apply(i,n,{A[i],A[i]}) ;
    }
    rep(i,q){
        ll t , x , v ;
        cin >> t >> x ;
        if(t == 1){
            cin >> v ;
            x-- ;
            segtree.apply(x,n,{-A[x]+mod,-A[x]+mod}) ;
            A[x] = v ;
            segtree.apply(x,n,{A[x],A[x]}) ;
        }
        else cout << segtree.prod(0,x).sum << endl ;
    }
}