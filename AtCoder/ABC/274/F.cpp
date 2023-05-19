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
typedef pair<ld,int> P ;
typedef tuple<ll,ll,int> TP ;
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

const ll inf = 2000000000000000000LL;

struct Frac{
    ll a , b;
    Frac(ll a_, ll b_): a(a_), b(b_) {}

    bool operator< (const Frac& x) const {
        return a * x.b > b * x.a ;
    }
    bool operator> (const Frac& x) const {
        return b * x.a < a * x.b ;
    }
    friend ostream &operator<<(ostream &os, const Frac &p) {
        if(p.a == 0) return os << "inf";
        return os << fixed << setprecision(5) << (ld)p.b / p.a;
    }
};

ll n, A ;
ll W[10101], X[10101], V[10101];
TP Y[10101];

int main(){
    fast_input_output
    cin >> n >> A ;
    rep(i,n) cin >> W[i] >> X[i] >> V[i];
    rep(i,n) Y[i] = {X[i],V[i],i};
    sort(Y,Y+n);
    ll res = 0;
    rep(i,n){
        auto [nx, nv, nw] = Y[i];
        vector<tuple<Frac,int,int>> vec; // {時刻, in/out, 番号}
        rep(jj,n){
            auto [px, pv, j] = Y[jj];
            if(nv == pv){
                if(nx <= px && px <= nx + A) {
                    Frac f(1LL,0);
                    vec.push_back({f,0,j});
                }
                continue;
            }
            if(nx > px){
                if(nv < pv){
                    vec.push_back({{pv-nv,nx-px},0,j});
                    vec.push_back({{pv-nv,nx+A-px},1,j});
                }
            }
            else{
                if(abs(px - nx) <= A){
                    vec.push_back({{1,0},0,j});
                    if(pv < nv){
                        vec.push_back({{abs(nv-pv),px-nx},1,j});
                    }
                    else{
                        vec.push_back({{abs(nv-pv),nx-px+A},1,j});
                    }
                }
                else{
                    if(pv < nv){
                        vec.push_back({{nv-pv,px-A-nx},0,j});
                        vec.push_back({{nv-pv,px-nx},1,j});
                    }
                }
            }
        }
        sort(vec.begin(),vec.end());
        set<int> st;
        ll val = 0;
        rep(j,vec.size()){
            auto[Z,t,id] = vec[j];
            if(t == 0) {
                st.insert(id);
                val += W[id];
            }
            if(t == 1) {
                st.erase(id);
                val -= W[id];
            }
            chmax(res,val);
        }
    }
    cout << res << endl;
}