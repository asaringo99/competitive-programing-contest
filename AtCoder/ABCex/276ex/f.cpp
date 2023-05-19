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

template<typename S , typename M>
struct SegmentTree{
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

        template<class F> int max_right(int l , F f) {
            int lef = l , rig = _n + 1 ;
            while(rig - lef > 1){
                int mid = (lef + rig) / 2 ;
                if(f(prod(lef,mid))) lef = mid ;
                else rig = mid ;
            }
            return rig ;
        }
        
        template<class F> int min_left(int r , F f) {
            int lef = -1 , rig = r ;
            while(rig - lef > 1){
                int mid = (lef + rig) / 2 ;
                if(f(prod(mid,rig))) rig = mid ;
                else lef = mid ;
            }
            return rig + 1 ;
        }
};

namespace monoid{
    ll inf = 1e16 ;

    struct S{
        modint sum;
        modint cnt;
    };

    function<S(S,S)> fs = [](S x , S y) -> S {
        return S{
            x.sum + y.sum,
            x.cnt + y.cnt,
        };
    };

    S es = {
        0,
        0,
    };
    S ee = {
        0,
        0,
    } ;

    struct M{
        ll a;
        bool operator == (M x) { return a == x.a ; }
    };

    M em = {0};

    function<S(S,M)> fa = [](S x , M y) -> S {
        return S{
            x.sum + y.a,
            x.cnt + 1,
        };
    };
} using namespace monoid;

int n ;
int A[202020];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    SegmentTree<S,M> segtree(202020,fs,fa,es,ee);
    modint sum = 0;
    rep(i,n){
        ll a = A[i];
        auto m = segtree.prod(0,A[i]);
        sum += m.cnt * a * 2;
        auto o = segtree.prod(A[i]+1,202020);
        sum += o.sum * 2;
        auto w = segtree.prod(A[i],A[i]+1);
        sum += (w.cnt * 2 + 1) * a;
        segtree.set(A[i],{A[i]});
        cout << sum / (i + 1) / (i + 1) << endl;
    }
}