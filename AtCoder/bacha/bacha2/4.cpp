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

struct Matrix{
    vector<vector<ld>> mat ;
    // 引数 : 答えになるベクトル , (vector<vector<ld>>でないことに注意)
    Matrix(vector<vector<ld>> A , vector<ld> X , ll k){
        mat.resize(X.size(),vector<ld>(1)) ;
        rep(i,X.size()) mat[i][0] = X[i] ;
        dynamic(A,k) ;
    }
    // 行列の積(A*B)を求める
    vector<vector<ld>> calculation(vector<vector<ld>> X , vector<vector<ld>> Y){
        int x = X.size() , y = Y[0].size() , n = Y.size() ;
        vector<vector<ld>> res(x,vector<ld>(y)) ;
        rep(i,x) rep(j,y) rep(k,n) {
            res[i][j] += X[i][k] * Y[k][j] ;
        }
        return res ;
    }
    // 繰り返し二乗法(ダブリング)
    void dynamic(vector<vector<ld>> A , ll k){
        int n = A.size() ;
        while(k > 0){
            if(k & 1) mat = calculation(A,mat) ;
            A = calculation(A,A) ;
            k >>= 1 ;
        }
    }

    inline ld operator [] (int i) { return mat[i][0] ; }
};

ld to_d(string S){
    reverse(S.begin(),S.end()) ;
    ld res = 0 ;
    for(char u : S){
        res /= 10 ;
        if(u == '.') break;
        res += u - '0' ;
    }
    return res ;
}

ll n ;
string S ;
ld p ;

int main(){
    // fast_input_output
    cin >> S >> n ;
    p = to_d(S) ;
    cout << p << endl ;
    vector<ld> X(2) ;
    X[0] = 1 ;
    X[1] = 0 ;
    vector<vector<ld>> A(2,vector<ld>(2)) ;
    A[0][0] = 1 - p ;
    A[0][1] = p ;
    A[1][0] = p ;
    A[1][1] = 1 - p ;
    Matrix mat(A,X,n) ;
    cout << fixed << setprecision(25) << mat[1] << endl ;
}