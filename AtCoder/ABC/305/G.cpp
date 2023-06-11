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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
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

template<typename T> struct Matrix{
    int row, col;
    vector<vector<T>> mat ;

    private:
        void init_(vector<vector<T>> A){
            row = A.size();
            col = A[0].size();
            mat = A;
        }
        
        void init_(vector<T> A, bool row_matrix = false){
            if(row_matrix) {
                col = (int)A.size();
                row = 1;
                mat.resize(1);
                mat[0] = A;
            }
            else {
                col = 1;
                row = (int)A.size();
                mat.resize(row,vector<T>(1));
                rep(i,row) mat[i][0] = A[i];
            }
        }

        Matrix<T> pow_(ll k){
            assert(row == col);
            vector<vector<T>> E(row,vector<T>(row,0));
            rep(i,row) rep(j,row) if(i == j) E[i][j] = 1;
            Matrix<T> res(E);
            Matrix<T> X(mat);
            while(k > 0){
                if(k & 1) res *= X;
                X *= X;
                k >>= 1 ;
            }
            return res;
        }

        void transpose_() {
            vector<vector<T>> res(col,vector<T>(row));
            rep(i,row) rep(j,col) res[j][i] = mat[i][j];
            mat = res;
            swap(row,col);
        }

        void concat_col_(vector<T> &Y) {
            Matrix X(Y);
            concat_col_(X);
        }
        void concat_col_(vector<vector<T>> &Y) {
            Matrix X(Y);
            concat_col_(X);
        }
        void concat_col_(Matrix &Y) {
            assert((int)Y.row == row);
            col += Y.col;
            rep(i,row) {
                rep(j,Y.col) mat[i].push_back(Y.mat[i][j]);
            }
        }

        void concat_row_(vector<T> &Y) {
            Matrix X(Y,true);
            concat_row_(X);
        }
        void concat_row_(vector<vector<T>> &Y) {
            Matrix X(Y);
            concat_row_(X);
        }
        void concat_row_(Matrix &Y) {
            assert((int)Y.col == col);
            row += Y.row;
            rep(i,Y.row) mat.push_back(Y.mat[i]);
        }

        void print_() {
            rep(i,row){
                rep(j,col) cout << mat[i][j] << " "; cout << endl;
            }
        }

    public:

        inline Matrix &operator+=(const Matrix Y) {
            rep(i,row) rep(j,col) mat[i][j] += Y.mat[i][j];
            return *this ;
        }

        inline Matrix &operator-=(const Matrix Y) {
            rep(i,row) rep(j,col) mat[i][j] -= Y.mat[i][j];
            return *this ;
        }

        inline Matrix &operator*=(const Matrix Y) {
            int x = row, y = Y.col, n = col;
            vector<vector<T>> res(x,vector<T>(y));
            rep(i,x) rep(j,y) rep(k,n) res[i][j] += mat[i][k] * Y.mat[k][j];
            swap(mat,res);
            row = x;
            col = y;
            return *this ;
        }

        inline Matrix operator-() const {
            rep(i,row) rep(j,col) mat[i][j] *= -1;
            return *this ;
        }

        inline Matrix operator+(const Matrix Y) const { return Matrix(*this) += Y; }

        inline Matrix operator-(const Matrix Y) const { return Matrix(*this) -= Y; }

        inline Matrix operator*(const Matrix Y) const { return Matrix(*this) *= Y; }

        inline bool operator==(const Matrix Y) const { return mat == Y.mat; }

        inline bool operator!=(const Matrix Y) const { return mat != Y.mat; }

        inline vector<T>&operator[](int i) { return mat[i] ; }

        Matrix(int n): row(n), col(0) { mat.resize(row); }
        Matrix(vector<T> A, bool row_matrix = false) { init_(A, row_matrix); }
        Matrix(vector<vector<T>> A){ init_(A); }
        void init(vector<T> A, bool row_matrix = false) { init_(A, row_matrix); }
        void init(vector<vector<T>> A) { init_(A); }
        size_t row_size() { return row; }
        size_t col_size() { return col; }
        Matrix pow(ll k){ return pow_(k); }
        void transpose() { transpose_(); }
        void concat_col(vector<vector<T>> &Y) { concat_col_(Y); }
        void concat_col(vector<T> &Y) { concat_col_(Y); }
        void concat_col(Matrix &Y) { concat_col_(Y); }
        void concat_row(vector<vector<T>> &Y) { concat_row_(Y); }
        void concat_row(vector<T> &Y) { concat_row_(Y); }
        void concat_row(Matrix &Y) { concat_row_(Y); }
        void print() { print_(); }
};

bool isok[202][202];
bool canuse[202];

ll n, m;

void solve(){
    cin >> n >> m;
    vector<string> S(m);
    rep(i,m) cin >> S[i];
    if(n <= 6){
        ll res = 0;
        rep(bt,1<<n){
            string s = "";
            rep(i,n){
                if(bt >> i & 1) s += 'b';
                else s += 'a';
            }
            bool ok = true;
            rep(i,n){
                rep(j,m){
                    string T = S[j];
                    int sz = T.size();
                    if(i+sz>n) continue;
                    bool gd = true;
                    rep(x,sz){
                        if(s[i+x] != T[x]) gd = false;
                    }
                    if(gd) ok = false;
                }
            }
            if(ok) res++;
        }
        cout << res << endl;
        return;
    }
    map<string,bool> mp;
    vector<string> kind;
    vector<string> rem;
    rep(bt,1<<6){
        string s = "";
        rep(i,6){
            if(bt >> i & 1) s += 'b';
            else s += 'a';
        }
        bool ok = true;
        rep(i,6){
            rep(j,m){
                string T = S[j];
                int sz = T.size();
                if(i+sz>6) continue;
                bool gd = true;
                rep(x,sz){
                    if(s[i+x] != T[x]) gd = false;
                }
                if(gd) ok = false;
            }
        }
        kind.push_back(s);
        if(ok) canuse[bt] = true;
    }
    rep(p,kind.size()){
        rep(q,kind.size()){
            string s = kind[p] + kind[q];
            bool ok = true;
            rep(i,12){
                rep(j,m){
                    string T = S[j];
                    int sz = T.size();
                    if(i+sz>12) continue;
                    bool gd = true;
                    rep(x,sz){
                        if(s[i+x] != T[x]) gd = false;
                    }
                    if(gd) ok = false;
                }
            }
            if(ok) {
                isok[p][q] = true;
            }
        }
    }
    vector<vector<modint>> M(kind.size(),vector<modint>(kind.size(),0));
    rep(i,kind.size()) rep(j,kind.size()){
        if(isok[j][i]) M[i][j] = 1;
    }
    // rep(i,M.size()){
    //     rep(j,M.size()) cout << M[i][j] << " "; cout << endl;
    // }
    vector<modint> b(kind.size(),0);
    rep(i,kind.size()) if(canuse[i]) b[i] = 1;
    Matrix mat(M), B(b);
    ll N = n / 6;
    ll Z = n % 6;
    mat = mat.pow(N-1);
    auto Y = mat * B;
    if(Z == 0){
        modint res = 0;
        rep(i,kind.size()){
            res += Y[i][0];
        }
        cout << res << endl;
        return;
    }
    rep(bt, 1 << Z){
        string s = "";
        rep(i,Z){
            if(bt >> i & 1) s += 'b';
            else s += 'a';
        }
        rem.push_back(s);
    }
    modint res = 0;
    rep(p,kind.size()){
        rep(q,rem.size()){
            string s = kind[p] + rem[q];
            bool ok = true;
            rep(i,s.size()){
                rep(j,m){
                    string T = S[j];
                    int sz = T.size();
                    if(i+sz>s.size()) continue;
                    bool gd = true;
                    rep(x,sz){
                        if(s[i+x] != T[x]) gd = false;
                    }
                    if(gd) ok = false;
                }
            }
            if(ok) {
                res += Y[p][0];
            }
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}