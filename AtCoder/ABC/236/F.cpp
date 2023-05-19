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
    Matrix(vector<vector<ll>> A){
        int n = A.size() , m = A[0].size() ;
        mat.resize(n,vector<ll>(m)) ;
        rep(i,n){
            rep(j,m) mat[i][j] = A[i][j] ;
        }
    }
    size_t size_col(){ return mat[0].size() ; }
    size_t size_row(){ return mat.size() ; }
    vector<ll>& operator [] (int i) { return mat[i] ; }
};


int n ;
P C[1 << 20] ;
ll B[20] ;

ll GauseJordan(Matrix &mat , bool is_extended){
    int n = mat.size_row() , m = mat.size_col() ;
    ll cost = 0 ;
    int rank = 0 ;
    for(int col = 0 ; col < m ; col++){
        if(col == m - 1 && is_extended) continue ;
        int pivot = -1 ;
        for(int row = rank ; row < n ; row++){
            if(mat[row][col] == 1){
                pivot = row ;
                break ;
            }
        }
        if(pivot == -1) continue ;
        swap(mat[rank],mat[pivot]) ;
        for(int row = 0 ; row < n ; row++){
            if(row == rank || mat[row][col] == 0) continue ;
            for(int col2 = 0 ; col2 < m ; col2++){
                mat[row][col2] ^= mat[rank][col2] ;
            }
        }
        cost += C[col].first ;
        rank++ ;
        if(rank == n) return cost ;
    }
    return -1 ;
}

ll solve(vector<vector<ll>> A){
    Matrix mat(A) ;
    int n = mat.size_row() , m = mat.size_col() ;
    ll res = GauseJordan(mat,false) ;
    return res ;
}


int main(){
    cin >> n ;
    vector<vector<ll>> A ;
    A.resize(n,vector<ll>((1<<n)-1,0)) ;
    rrep(i,1,1<<n) {
        ll c ;
        cin >> c ;
        C[i-1] = P(c,i) ;
    }
    sort(C,C+(1<<n)-1) ;
    rep(S,(1<<n)-1){
        P p = C[S] ;
        ll c = p.first , val = p.second ;
        rep(i,n) if(val >> i & 1) A[i][S] = 1 ;
    }
    cout << solve(A) << endl ;
}