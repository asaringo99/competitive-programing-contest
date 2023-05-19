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

template<int MAX_COL, typename T=bool> struct BitMatrix{

    private:
        int row, col;
        vector<bitset<MAX_COL>> mat;

        void init_(vector<vector<T>> A){
            row = A.size();
            col = A[0].size();
            mat.resize(row);
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(A[i][j] != 0) mat[i][j] = 1;
                    else mat[i][j] = 0;
                }
            }
        }
        
        void init_(vector<T> A, bool row_matrix = false){
            if(row_matrix) {
                col = (int)A.size();
                row = 1;
                mat.resize(1);
                for(int i = 0; i < col; i++){
                    if(A[i] != 0) mat[0][i] = 1;
                    else mat[0][i] = 0;
                }
            }
            else {
                col = 1;
                row = (int)A.size();
                mat.resize(row);
                for(int i = 0; i < row; i++){
                    if(A[i] != 0) mat[i][0] = 1;
                    else mat[i][0] = 0;
                }
            }
        }

        void transpose_() {
            vector<bitset<MAX_COL>> res(col);
            rep(i,row) rep(j,col) res[j][i] = mat[i][j];
            mat = res;
            swap(row,col);
        }
        
        void flip_() {
            rep(i,row) rep(j,col) mat[i][j].flip();
        }

        void concat_col_(vector<T> &Y) {
            BitMatrix X(Y);
            concat_col_(X);
        }
        void concat_col_(vector<vector<T>> &Y) {
            BitMatrix X(Y);
            concat_col_(X);
        }
        void concat_col_(BitMatrix &Y) {
            assert((int)Y.row == row);
            rep(i,row) {
                rep(j,Y.col) mat[i][j+col] = (Y.mat[i][j]);
            }
            col += Y.col;
        }

        void concat_row_(vector<T> &Y) {
            BitMatrix X(Y,true);
            concat_row_(X);
        }
        void concat_row_(vector<vector<T>> &Y) {
            BitMatrix X(Y);
            concat_row_(X);
        }
        void concat_row_(BitMatrix &Y) {
            assert((int)Y.col == col);
            row += Y.row;
            rep(i,Y.row) mat.push_back(Y.mat[i]);
        }

        void print_() {
            rep(i,row){
                rep(j,col) cout << mat[i][j]; cout << endl;
            }
        }

    public:

        inline BitMatrix &operator&=(const BitMatrix Y) {
            rep(i,row) mat[i] &= Y.mat[i];
            return *this ;
        }

        inline BitMatrix &operator|=(const BitMatrix Y) {
            rep(i,row) mat[i] |= Y.mat[i];
            return *this ;
        }
        
        inline BitMatrix &operator^=(const BitMatrix Y) {
            rep(i,row) mat[i] ^= Y.mat[i];
            return *this ;
        }

        inline BitMatrix operator&(const BitMatrix Y) const { return BitMatrix(*this) &= Y; }

        inline BitMatrix operator|(const BitMatrix Y) const { return BitMatrix(*this) |= Y; }

        inline BitMatrix operator^(const BitMatrix Y) const { return BitMatrix(*this) += Y; }

        inline bool operator==(const BitMatrix Y) const { return mat == Y.mat; }

        inline bool operator!=(const BitMatrix Y) const { return mat != Y.mat; }

        inline bitset<MAX_COL>&operator[] (int i) {return mat[i]; }

        BitMatrix(int n): row(n), col(0) { mat.resize(row); }
        BitMatrix(vector<T> A, bool row_matrix = false) { init_(A, row_matrix); }
        BitMatrix(vector<vector<T>> A){ init_(A); }
        void init(vector<T> A, bool row_matrix = false) { init_(A, row_matrix); }
        void init(vector<vector<T>> A) { init_(A); }
        size_t row_size() { return row; }
        size_t col_size() { return col; }
        void transpose() { transpose_(); }
        void flip() { flip_(); }
        void concat_col(vector<vector<T>> &Y) { concat_col_(Y); }
        void concat_col(vector<T> &Y) { concat_col_(Y); }
        void concat_col(BitMatrix &Y) { concat_col_(Y); }
        void concat_row(vector<vector<T>> &Y) { concat_row_(Y); }
        void concat_row(vector<T> &Y) { concat_row_(Y); }
        void concat_row(BitMatrix &Y) { concat_row_(Y); }
        void print() { print_(); }
};

const int MAX_COL = 2510;
using Matrix = BitMatrix<MAX_COL, bool>;

template<typename T=bool> struct GaussJordan{
    private:
        int rank;
        vector<bool> solution;

        int sweep_out_(Matrix &A , bool is_extended = false){
            rank = 0 ;
            for(int col = 0 ; col < A.col_size() ; col++){
                if(is_extended && col == A.col_size() - 1) break ;

                int pivot = -1 ;
                for(int row = rank ; row < A.col_size() ; row++){
                    if(A[row][col]){
                        pivot = row ;
                        break ;
                    }
                }

                if(pivot == -1) continue ;
                swap(A[pivot] , A[rank]) ;
                for(int row = 0 ; row < A.row_size() ; row++){
                    if(row != rank && A[row][col]) A[row] ^= A[rank] ;
                }
                rank++ ;
            }
            return rank ;
        }
        
        vector<bool> solve_simultaneous_equation_(vector<vector<T>> &A , vector<T> &b){
            Matrix X(A), Y(b);
            return solve_simultaneous_equation_(X, Y);
        }
        vector<bool> solve_simultaneous_equation_(Matrix &A , vector<T> &b){
            Matrix Y(b);
            return solve_simultaneous_equation_(A, Y);
        }
        vector<bool> solve_simultaneous_equation_(vector<vector<T>> &A , Matrix &b){
            Matrix X(A);
            return solve_simultaneous_equation_(X, b);
        }
        vector<bool> solve_simultaneous_equation_(Matrix &A , Matrix &b){
            A.concat_col(b);
            return solve_simultaneous_equation_(A);
        }
        vector<bool> solve_simultaneous_equation_(vector<vector<T>> &A){
            return solve_simultaneous_equation_(to_matrix(A));
        }
        vector<bool> solve_simultaneous_equation_(Matrix &M){

            int n = M.row_size() , m = M.col_size();

            rank = sweep_out_(M,true);

            for(int row = rank ; row < n ; row++) if(M[row][n]) return {};

            vector<bool> res;
            res.resize(rank);
            for(int i = 0 ; i < rank; i++) res[i] = M[i][m];

            return solution = res;
        }

    public:
        GaussJordan(){}
        int sweep_out(Matrix &A) { return sweep_out_(A, false); }
        int sweep_out(Matrix &A, bool is_extended) { return sweep_out_(A, is_extended); }
        vector<bool> solve_simultaneous_equation(Matrix &A , Matrix &b) { return solve_simultaneous_equation_(A, b); }
        vector<bool> solve_simultaneous_equation(Matrix &A , vector<T> &b) { return solve_simultaneous_equation_(A, b); }
        vector<bool> solve_simultaneous_equation(vector<vector<T>> &A , vector<T> &b) { return solve_simultaneous_equation_(A, b); }
        vector<bool> solve_simultaneous_equation(vector<vector<T>> &A , Matrix &b) { return solve_simultaneous_equation_(A, b); }
        vector<bool> solve_simultaneous_equation(vector<vector<T>> &A) { return solve_simultaneous_equation_(A); }
        vector<bool> solve_simultaneous_equation(Matrix A) { return solve_simultaneous_equation_(A); }
        int get_rank() { return rank; }
        vector<T> get_solution() { return solution; }
};

int n, m, d;
vector<vector<char>> S;
vector<vector<bool>> A;

bool solve(){
    S.clear();
    A.clear();
    cin >> m >> n >> d;
    if(m == 0 && n == 0 && d == 0) return false;
    S.resize(n, vector<char>(m));
    A.resize(n, vector<bool>(m));
    rep(i,n) rep(j,m) cin >> S[i][j], A[i][j] = S[i][j] - '0';
    vector<vector<bool>> M(n*m,vector<bool>(n*m+1,0));
    vector<bool> res(n*m);
    rep(i,n) rep(j,m){
        M[i*m+j][i*m+j] = 1;
        rep(x,n) rep(y,m){
            int dist = abs(i - x) + abs(j - y);
            if(dist == d) {
                M[i*m+j][x*m+y] = 1;
            }
        }
        if(!A[i][j]) M[i*m+j][n*m] = 1;
    }
    GaussJordan gj;

    auto ans = gj.solve_simultaneous_equation(Matrix(M));
    if(ans.empty()) cout << 0 << endl;
    else cout << 1 << endl;
    return 1;
}

int main(){
    fast_io
    while(1){
        if(!solve()) {
            return 0;
        }
    }
}