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

const int MAX_N = 2010101 ;

modint inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
modint fac[MAX_N+1] ; // (n!) (mod p) を格納

modint powmod(modint x , ll n){
    modint res = 1 ;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1 ;
    }
    return res ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void f(){
    inv[0] = 1 ; inv[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        inv[i] = powmod(i,mod-2) * inv[i-1];
    }
}

// 階乗のmodを配列に格納
void g(){
    fac[0] = 1 ; fac[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        fac[i] = fac[i-1] * i;
    }
}

//nCrの計算
modint combination(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] * inv[r];
}

modint permutation(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r];
}

void init(){ f() ; g() ; }

int n;
vector<ll> B, C;

int main(){
    fast_input_output
    init();
    cin >> n;
    B = vector<ll>(n);
    C = vector<ll>(n);
    rep(i,n) cin >> B[i] >> C[i];
    vector<tuple<ll,ll,int>> S;
    rep(i,n){
        S.push_back({B[i],1,i});
        S.push_back({C[i],-1,i});
    }
    sort(all(S));
    modint res = 0;
    modint dead = 0;
    modint cnt = 0;
    modint preval = 0;
    modint bsum = 0;
    rep(i,S.size()){
        auto[now, c, idx] = S[i];
        modint finval = now;
        modint u = finval - preval;
        modint v = finval + preval;
        modint x = u * (u + 1) / 2 * cnt * cnt;
        modint y = u * (v + 1) / 2 * cnt;
        modint z = u * cnt * dead;
        modint value = x - y + z + bsum * u;
        
        preval = now;
        dead += u * cnt;
        res += value;
        bsum += c * B[idx];
        cnt += c;
        cout << res << endl;
    }
    // res-=1;
    rep(i,n) res /= (C[i] - B[i] + 1);
    cout << res << endl;
}