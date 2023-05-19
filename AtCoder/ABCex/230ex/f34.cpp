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
};

namespace monoid{
    ll inf = 1e16 ;

    struct S{
        modint sum;
    };

    function<S(S,S)> fs = [](S x , S y) -> S {
        return S{
            x.sum + y.sum,
        };
    };

    S es = {
        0,
    };
    S ee = {
        0,
    } ;

    struct M{
        ll a ;
        bool operator == (M x) { return a == x.a ; }
    };

    M em = {0};

    function<S(S,M)> fa = [](S x , M y) -> S {
        return S{
            x.sum + y.a,
        };
    };
} using namespace monoid;

int n;
ll A[202020], s[202020];
map<ll,vector<int>> I;
modint dp[202020];

int main(){
    fast_io
    cin >> n;
    SegmentTree<S,M> segtree(n+1,fs,fa,es,ee);
    I[0].push_back(0);
    rep(i,n) cin >> A[i], s[i+1] = s[i] + A[i], I[s[i+1]].push_back(i+1);
    dp[0] = 1;
    modint res = 0;
    rep(i,n){
        ll v = s[i];
        auto it = lower_bound(all(I[v]), i);
        if(it == I[v].begin()){
            dp[i] += segtree.prod(0,i).sum;
            segtree.set(i,{dp[i].x});
        }
        else{
            it--;
            int id = *it;
            dp[i] += segtree.prod(id,i).sum;
            segtree.set(i,{dp[i].x});
        }
        res += dp[i];
    }
    cout << res << endl;
}