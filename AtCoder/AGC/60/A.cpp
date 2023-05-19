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

int n;
string S;
// dp[][i][j]: i: 1個前, j: 2個前
modint dp[5050][27][27];

int main(){
    fast_io
    cin >> n >> S;
    rep(i,n-1){
        if(S[i] == S[i+1] && S[i] != '?'){
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,n-2){
        if(S[i] == S[i+2] && S[i] != '?'){
            cout << 0 << endl;
            return 0;
        }
    }
    dp[0][26][26] = 1;
    rep(i,n){
        if(S[i] == '?'){
            rep(j,27){
                rep(k,27){
                    rep(l,26){
                        int x = -1, y = -1;
                        if(i < n-1) x = S[i+1] - 'a';
                        if(i < n-2) y = S[i+2] - 'a';
                        if(x == k) continue;
                        if(y == l) continue;
                        if(k == l) continue;
                        if(l == j) continue;
                        if(j == k && j < 26) continue;
                        dp[i+1][l][k] += dp[i][k][j];
                    }
                }
            }
        }
        else{
            rep(j,27){
                rep(k,27){
                    int s = S[i] - 'a';
                    int x = -1, y = -1;
                    if(i < n-1) x = S[i+1] - 'a';
                    if(i < n-2) y = S[i+2] - 'a';
                    if(x == k) continue;
                    if(y == s) continue;
                    if(k == s) continue;
                    if(s == j) continue;
                    if(j == k && j < 26) continue;
                    dp[i+1][s][k] += dp[i][k][j];
                }
            }
        }
    }
    modint res = 0;
    rep(i,26) rep(j,26) res += dp[n][i][j];
    cout << res << endl;
}