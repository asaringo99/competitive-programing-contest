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

modint dp[707][707][707][3];
int A[707];

void solve(){
    int n;
    string S;
    cin >> S;
    n = S.size();
    rep(i,n){
        int cnt = S[i] == '(' ? 1 : -1;
        A[i+1] = A[i] + cnt;
    }
    dp[0][0][0][0] = 1;
    rep(i,n){
        int lim = A[i];
        rep(j,lim+1){
            rep(k,lim+1){
                if(j+k>lim) break;
                // cout << i << " " << j << " " << k << endl;
                if(S[i] == '('){
                    dp[i+1][j+1][k][1] += dp[i][j][k][0];
                    dp[i+1][j][k+1][2] += dp[i][j][k][0];
                    dp[i+1][j][k][0] += dp[i][j][k][0];
                    dp[i+1][j][k][0] += dp[i][j][k][1];
                    dp[i+1][j][k][0] += dp[i][j][k][2];
                }
                else{
                    if(k + j < lim) dp[i+1][j][k][1] += dp[i][j][k][0];
                    if(k + j < lim) dp[i+1][j][k][2] += dp[i][j][k][0];
                    if(j > 0) dp[i+1][j-1][k][0] += dp[i][j][k][0];
                    if(j > 0) dp[i+1][j-1][k][0] += dp[i][j][k][1];
                    if(j > 0) dp[i+1][j-1][k][0] += dp[i][j][k][2];
                    if(k > 0) dp[i+1][j][k-1][0] += dp[i][j][k][0];
                    if(k > 0) dp[i+1][j][k-1][0] += dp[i][j][k][1];
                    if(k > 0) dp[i+1][j][k-1][0] += dp[i][j][k][2];
                }
            }
        }
    }
    modint res = 0;
    rep(i,3) {
        res += dp[n][0][0][i];
    }
    cout << res << endl;
}

int main(){
    fast_io
    // init();
    solve();
}