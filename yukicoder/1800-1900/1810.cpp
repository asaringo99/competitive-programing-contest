#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

struct MATRIX{
    vector<vector<ll>> mat ;
    // 引数 : 答えになるベクトル , (vector<vector<ll>>でないことに注意)
    MATRIX(vector<ll> X , vector<vector<ll>> A , ll k){
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

ll a , b , n ;

int main(){
    cin >> a >> b >> n ;
    vector<vector<ll>> A = {{a,b},{1,0}} ;
    vector<ll> X = {1,1} ;
    rep(i,n){
        ll t ;
        cin >> t ;
        ll s = t / 2 ;
        MATRIX mat(X,A,s) ;
        ll v = t % 2 == 0 ? 0 : (mat[0] * a % mod + mat[1] * b % mod) % mod ;
        ll res = (mat[0] + mat[1] + v) % mod ;
        cout << res << endl ;
    }
}