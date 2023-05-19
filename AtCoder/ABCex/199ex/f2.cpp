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

const int mod = 1000000007 ;
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

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

ll n , m , k ;
ll B[101] ;
vector<int> G[101] ;

int main(){
    cin >> n >> m >> k ;
    rep(i,n) cin >> B[i] ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    vector<vector<ll>> A(n,vector<ll>(n,0)) ;
    vector<ll> X(n,0) ;
    rep(v,n){
        int volume = G[v].size() ;
        A[v][v] = (powmod(2,mod-2) * volume % mod + m - volume) % mod ;
        rep(i,G[v].size()){
            int u = G[v][i] ;
            A[v][u] = (powmod(2,mod-2)) % mod ;
        }
    }
    rep(i,n) X[i] = B[i] ;
    Matrix mat(A,X,k) ;
    rep(i,n) cout << powmod(powmod(m,k),mod-2) * mat[i] % mod << endl ;
}