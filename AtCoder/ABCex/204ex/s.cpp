#include <bits/stdc++.h>
using namespace std ;
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

const int mod = 998244353 ;

struct Matrix{
    vector<vector<ll>> mat ;
    // 引数 : 答えになるベクトル , (vector<vector<ll>>でないことに注意)
    Matrix(vector<vector<ll>> A , vector<ll> X , ll k){
        mat.resize(X.size(),vector<ll>(1)) ;
        rep(i,X.size()) mat[i][0] = X[i] ;
        dynamic(A,k) ;
    }
    // 行列の積(A*B)を求める
    vector<vector<ll>> calculation(vector<vector<ll>> X , vector<vector<ll>> Y){
        int x = X.size() , y = Y[0].size() , n = Y.size() ;
        vector<vector<ll>> res(x,vector<ll>(y)) ;
        rep(i,x) rep(j,y) rep(k,n) {
            (res[i][j] += X[i][k] * Y[k][j]) %= mod ;
        }
        return res ;
    }
    // 繰り返し二乗法(ダブリング)
    void dynamic(vector<vector<ll>> A , ll k){
        int n = A.size() ;
        while(k > 0){
            if(k & 1) mat = calculation(A,mat) ;
            A = calculation(A,A) ;
            k >>= 1 ;
        }
    }

    inline ll operator [] (int i) { return mat[i][0] ; }
};

ll H , W ;
vector<int> U , D , C ;

ll f(int a){
    vector<bool> S(H,0) ;
    rep(i,H) if(a >> i & 1) S[i] = true ;
    vector<ll> dp(H+10,0) ;
    dp[0] = 1 ;
    rep(i,H){
        if(S[i]) dp[i+1] = dp[i] ;
        if(!S[i]) dp[i+1] += dp[i] ;
        if(!S[i] && !S[i+1] && i + 1 < H) dp[i+2] += dp[i] ;
    }
    return dp[H] ;
}

int main(){
    cin >> H >> W ;
    rep(S,1<<H){
        U.push_back(S) ;
        C.push_back(f(S)) ;
    }
    int m = U.size() ;
    vector<ll> X(m,0) ;
    vector<vector<ll>> A(m,vector<ll>(m,0)) ;
    rep(i,m){
        X[i] = C[i] ;
        rep(j,m){
            if((U[j] & U[i]) != 0) continue ;
            A[i][j] = f(U[j] | U[i]) ;
        }
    }
    Matrix mat(A,X,W-1) ;
    cout << mat[0] << endl ;
}