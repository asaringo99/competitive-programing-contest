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

const int mod = 1000000007 ;

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

modint dp[4030][101][2];

void solve(){
    int n, L;
    cin >> n >> L;
    vector<ll> A(n+1), B(n+1);
    rrep(i,1,n+1) cin >> A[i] >> B[i];
    rrep(i,1,n+1){
        dp[A[i]][i][0] = 1;
        if(A[i] != B[i]) dp[B[i]][i][1] = 1;
    }
    rrep(i,1,L+1){
        rrep(j,1,n+1){
            rrep(k,1,n+1){
                if(j == k) continue;
                // 0 -> 0
                {
                    int pw = B[j];
                    int nh = A[k];
                    if(nh == pw){
                        dp[i+nh][k][0] += dp[i][j][0];
                    }
                }
                // 1 -> 0
                {
                    int pw = A[j];
                    int nh = A[k];
                    if(nh == pw){
                        dp[i+nh][k][0] += dp[i][j][1];
                    }
                }
                if(A[k] == B[k]) continue;
                // 0 -> 1
                {
                    int pw = B[j];
                    int nh = B[k];
                    if(nh == pw){
                        dp[i+nh][k][1] += dp[i][j][0];
                    }
                }
                // 1 -> 1
                {
                    int pw = A[j];
                    int nh = B[k];
                    if(nh == pw){
                        dp[i+nh][k][1] += dp[i][j][1];
                    }
                }
            }
        }
    }
    modint res = 0;
    rrep(i,1,n+1) rep(j,2) res += dp[L][i][j];
    pt(res);
}

int main(){
    fast_io
    solve();
}