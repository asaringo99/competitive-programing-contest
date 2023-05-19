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

struct NTT{
    private:
        int n , logn = 0;
        modint BASE = 3 ;
        vector<modint> vec , X , Y ;
        vector<vector<modint>> ROOT , INV_ROOT ;

        // ビルドする（畳み込み→逆変換） 
        void build(){
            // 畳み込み
            vector<modint> V = convolution(X,Y) ;
            // 逆変換
            vec = ifft(V) ;
        }
        // バタフライ演算を行うために配置を変換
        inline void arrangeIndexForBatafly(vector<modint> &A , int logn){
            for (int i = 0; i < n; i++) {
                int j = 0;
                for (int k = 0; k < logn; k++) j |= (i >> k & 1) << (logn - 1 - k);
                if (i < j) swap(A[i], A[j]);
            }
        }
        // FFT, IFFT のロジック
        inline vector<modint> sub_fft(vector<modint> A , bool inverse){
            // バタフライ演算
            arrangeIndexForBatafly(A,logn) ;
            int lg = 1 ;
            for(int block = 1 ; block < n ; block *= 2){
                // block内 の j 番目に対する処理
                for(int j = 0 ; j < block ; j++){
                    // w , v : 重み
                    modint w = inverse ? ROOT[lg][j] : INV_ROOT[lg][j] ;
                    modint v = inverse ? ROOT[lg][j+block] : INV_ROOT[lg][j+block] ;
                    for(int i = 0 ; i < n ; i += 2 * block){
                        modint s = A[j+i] ;
                        modint t = A[j+i+block] ;
                        A[j + i] = s + t * w ;
                        A[j + i + block] = s + t * v ;
                    }
                }
                lg++ ;
            }
            if(inverse) for(int i = 0 ; i < n ; i++) A[i] /= n ;
            return A ;
        }
        // 高速数論変換（NTT）
        inline vector<modint>  fft(vector<modint> A) { return sub_fft(A,false)  ; }
        // 逆高速数論変換（INTT）
        inline vector<modint> ifft(vector<modint> A) { return sub_fft(A,true) ; }
        // 畳み込み（Comvolution）を行う
        inline vector<modint> convolution(vector<modint> A , vector<modint> B){
            X = fft(A) , Y = fft(B) ;
            vector<modint> V(n,0) ;
            for(int i = 0 ; i < n ; i++) V[i] = X[i] * Y[i] ;
            return V ;
        }

    public:
        NTT(vector<modint> A , vector<modint> B){
            BASE = BASE.pow(119) ;
            int n1 = A.size() , n2 = B.size() , n_ = n1 + n2 - 1 ;
            n = 1 ;
            while(n < n_) n *= 2 , logn++ ;
            X.resize(n,0) , Y.resize(n,0) ;
            for(int i = 0 ; i < n1 ; i++) X[i] = A[i] ;
            for(int i = 0 ; i < n2 ; i++) Y[i] = B[i] ;

            rep(i,logn+1) {
                vector<modint> pwr , ipwr ;
                modint POW = BASE.pow(1<<(23-i)) ;
                modint INV_POW = POW.inverse() ;
                modint powval = 1 , inv_powval = 1 ;
                rep(j,(1<<i)+1) {
                    pwr.push_back(powval) ;
                    powval *= POW ;
                }
                rep(j,(1<<i)+1) {
                    ipwr.push_back(inv_powval) ;
                    inv_powval *= INV_POW ;
                }
                ROOT.push_back(pwr) ;
                INV_ROOT.push_back(ipwr) ;
            }
            build() ;
        }
        inline modint operator [] (int i) { return vec[i] ; }
        size_t fft_size() { return n ; } // 2の冪乗が返ってくる
        vector<modint> get_fft() { return vec ; }
};

const int MAX_N = 1010101;

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

int main(){
    fast_io
    init();
    vector<modint> A(1010101, 0), B(1010101, 0);
    rrep(i,1,1010101){
        // A[i] = inv[i] * inv[i-2];
        A[i] = inv[i-1] * inv[i+1] * i;
    }
    rrep(i,1,1010101){
        // B[i] = inv[i] * inv[i-1] * (i + 1);
        B[i] = inv[i+1] * inv[i-1];
    }
    NTT ntt(A,B);
    vector<modint> X = ntt.get_fft();
    int z;
    cin >> z;
    rep(i,z){
        ll n;
        cin >> n;
        if(n == 2) cout << 1 << endl;
        else cout << X[n] * fac[n] * fac[n-3] << endl;
    }
}