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

ll n, m, q ;

int main(){
    fast_input_output
    cin >> n >> m >> q;
    rep(i,q){
        ll sx, sy, gx, gy;
        // o 最小, e 次
        ll o_y, o_t, e_y, e_t;
        cin >> sx >> gx >> sy >> gy;

        if((gy - sy + 1) % 2 == 0){
            o_y = (gy - sy + 1) / 2;
            e_y = (gy - sy + 1) / 2;
        }
        else{
            if((sx + sy) % 2 == 0){
                e_y = (gy - sy + 1) / 2 + 1;
                o_y = (gy - sy + 1) / 2;
            }
            else{
                e_y = (gy - sy + 1) / 2 + 1;
                o_y = (gy - sy + 1) / 2;
            }
        }

        if((gx - sx + 1) % 2 == 0){
            o_t = (gx - sx + 1) / 2;
            e_t = (gx - sx + 1) / 2;
        }
        else{
            if((sx + sy) % 2 == 0){
                e_t = (gx - sx + 1) / 2 + 1;
                o_t = (gx - sx + 1) / 2;
            }
            else{
                e_t = (gx - sx + 1) / 2;
                o_t = (gx - sx + 1) / 2 + 1;
            }
        }

        // cout << e_y << " " << o_y << " " << e_t << " " << o_t << endl;

        modint e_s = 0, o_s = 0;
        if((sx + sy) % 2 == 0){
            // 初期化
            e_s = (sx - 1) * m + sy;
            e_s *= e_y;
            e_s += (e_y - 1) * e_y;
            modint e_p = e_y * 2 * m % mod;
            e_s *= e_t;
            e_s += e_p * (e_t - 1) * e_t / 2;
            // 初期化
            o_s = sx * m + sy + 1;
            o_s *= o_y;
            o_s += (o_y - 1) * o_y;
            modint o_p = o_y * 2 * m;
            o_s *= o_t;
            o_s += o_p * (o_t - 1) * o_t / 2;

            cout << o_s + e_s << endl;
        }
        else{
            // 初期化
            o_s = (sx - 1) * m + sy + 1;
            o_s *= o_y;
            o_s += (o_y - 1) * o_y;
            modint o_p = o_y * 2 * m % mod;
            o_s *= o_t;
            o_s += o_p * (o_t - 1) * o_t / 2;
            // 初期化
            e_s = sx * m + sy;
            e_s *= e_y;
            e_s += (e_y - 1) * e_y;
            modint e_p = e_y * 2 * m % mod;
            e_s *= e_t;
            e_s += e_p * (e_t - 1) * e_t / 2;

            cout << o_s + e_s << endl;
        }
    }
}