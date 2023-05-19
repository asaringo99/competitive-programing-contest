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
#define V vector<ll>

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
set<int> st;
vector<int> A[5];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,5) A[i].resize(n);
    rep(i,5) rep(j,n) cin >> A[i][j], st.insert(A[i][j]);
    rep(i,5) sort(A[i].begin(), A[i].end());
    modint sum = 0;
    for(int u : st){
        modint x = u;
        vector<modint> C, Mn, Mx;
        rep(i,5){
            auto it = upper_bound(A[i].begin(), A[i].end(), u);
            auto jt = lower_bound(A[i].begin(), A[i].end(), u);
            C.push_back(it - jt);
            Mn.push_back(jt - A[i].begin());
            Mx.push_back(n - (it - A[i].begin()));
        }
        rrep(S,1,1<<5){
            vector<pair<modint,modint>> vec;
            modint cnt = 1;
            int bt = 0;
            rep(i,5){
                if(S >> i & 1) bt++;
                if(S >> i & 1){
                    cnt *= C[i];
                }
                else{
                    vec.push_back({Mn[i],Mx[i]});
                }
            }
            cnt *= x;
            if(bt == 1){
                modint val = 0;
                val += vec[0].first * vec[1].first * vec[2].second * vec[3].second;
                val += vec[0].first * vec[2].first * vec[1].second * vec[3].second;
                val += vec[0].first * vec[3].first * vec[1].second * vec[2].second;
                val += vec[1].first * vec[2].first * vec[0].second * vec[3].second;
                val += vec[1].first * vec[3].first * vec[0].second * vec[2].second;
                val += vec[2].first * vec[3].first * vec[0].second * vec[1].second;
                sum += val * cnt;
            }
            if(bt == 2){
                modint val = 0;
                val += vec[0].first * vec[1].first * vec[2].second;
                val += vec[0].first * vec[2].first * vec[1].second;
                val += vec[1].first * vec[2].first * vec[0].second;
                val += vec[0].first * vec[1].second * vec[2].second;
                val += vec[1].first * vec[0].second * vec[2].second;
                val += vec[2].first * vec[0].second * vec[1].second;
                sum += val * cnt;
            }
            if(bt == 3){
                modint val = 0;
                val += vec[0].first * vec[1].first;
                val += vec[0].first * vec[1].second;
                val += vec[0].second * vec[1].first;
                val += vec[0].second * vec[1].second;
                sum += val * cnt;
            }
            if(bt == 4){
                modint val = 0;
                val += vec[0].first + vec[0].second;
                sum += val * cnt;
            }
            if(bt == 5){
                sum += cnt;
            }
        }
    }
    cout << sum << endl;
}