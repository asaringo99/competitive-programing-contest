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
vector<int> G[5050];
ll dp[5050][5050][2];
ll ep[5050][5050][2];
int child[5050];

void dfs(int v, int prev){
    child[v] = 1;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        child[v] += child[u];
    }
}

void rec(int v, int prev){
    dp[v][1][1] = 1;
    dp[v][0][0] = 1;
    ep[v][1][1] = 1;
    ep[v][0][0] = 1;
    int now = 1;
    for(int u : G[v]){
        if(u == prev) continue;
        rec(u,v);
        int c = child[u];
        rrep(i,1,now+1){
            rrep(j,1,c+1){
                // 頂点を加えた場合
                (ep[v][i+j][1] += dp[v][i][1] * dp[u][j][0]) %= mod;
                (ep[v][i+j-1][1] += dp[v][i][1] * dp[u][j][1]) %= mod;
            }
        }
        rep(i,now){
            rrep(j,1,c+1){
                // 頂点を加えない場合
                (ep[v][i+j][0] += dp[v][i][0] * dp[u][j][0]) %= mod;
                (ep[v][i+j][0] += dp[v][i][0] * dp[u][j][1]) %= mod;
            }
        }
        now += c;
        rep(i,now+1){
            rep(j,2){
                // 頂点を加えた場合
                dp[v][i][j] = ep[v][i][j];
            }
        }
    }
    // dp[v][0][0] = 1;
}

int main(){
    fast_io
    cin >> n ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    // dp.resize(n+1,vector<vector<ll>>(n+1,vector<ll>(2,0)));
    dfs(0,-1);
    // rep(i,n+1) rep(j,n+1) rep(k,2) dp[i][j][k] = -1;
    rec(0,-1);
    rrep(i,1,n+1) cout << (dp[0][i][0] + dp[0][i][1]) % mod << endl;
}