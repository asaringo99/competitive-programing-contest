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
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
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

int n ;
ll A[303030];
modint dp[303030];
modint dp2[303030];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    modint sum = 0;
    modint sum2 = 0;
    deque<pair<ll,modint>> que, que2;
    que.push_back({0,1});
    que2.push_back({0,1});
    rrep(i,1,n+1){
        ll a = A[i-1];
        modint dpsum = 0;
        modint dpsum2 = 0;
        while(!que.empty()){
            auto[av,dpv] = que.back();
            if(av > a) break;
            que.pop_back();
            sum -= dpv * av;
            dpsum += dpv;
        }
        while(!que2.empty()){
            auto[av,dpv] = que2.back();
            if(av != 0 && av < a) break;
            que2.pop_back();
            sum2 -= dpv * av;
            dpsum2 += dpv;
        }
        sum += dpsum * a;
        sum2 += dpsum2 * a;
        dp[i] = sum - sum2;
        // cout << sum << " " << sum2 << endl;
        que.push_back({a,dpsum});
        que2.push_back({a,dpsum2});
        que.push_back({0,dp[i]});
        que2.push_back({0,dp[i]});
    }
    cout << dp[n] << endl;
}