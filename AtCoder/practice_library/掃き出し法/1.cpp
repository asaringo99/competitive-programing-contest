#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const ld EPS = 1e-10 ;

struct Matrix{
    vector<vector<ld>> mat ;
    Matrix(int n , int m , ld x = 0){
        mat.assign(n,vector<ld>(m,x)) ;
    }
    size_t size_row() const { return mat.size() ; }
    size_t size_col() const { return mat[0].size() ; }
    vector<ld>& operator [] (int i) { return mat[i] ; }
};

int GaussJordan(Matrix &mat , bool is_extended = false){
    int n = mat.size_row() , m = mat.size_col() , rank = 0 ;
    for(int col = 0 ; col < m ; col++){
        if(is_extended && col == m - 1) continue ;
        int pivot = -1 ;
        ld e = EPS ;
        for(int row = rank ; row < n ; row++){
            if(abs(mat[row][col]) > e){
                e = mat[row][col] ;
                pivot = row ;
            }
        }
        if(pivot == -1) continue ;
        swap(mat[rank],mat[pivot]) ;
        ld fac = mat[rank][col] ;
        for(int col2 = 0 ; col2 < m ; col2++) mat[rank][col2] /= fac ;
        for(int row = 0 ; row < n ; row++){
            if(row == rank || abs(mat[row][col]) < EPS) continue ;
            ld gac = mat[row][col] ;
            for(int col2 = 0 ; col2 < m ; col2++){
                mat[row][col2] -= mat[rank][col2] * gac ;
            }
        }
        rank++ ;
    }
    return rank ;
};

vector<ld> Solution(vector<vector<ld>> A , vector<ld> b){
    int n = A.size() , m = A[0].size() ;
    Matrix mat(n,m+1) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++) mat[i][j] = A[i][j] ;
        mat[i][m] = b[i] ;
    }
    int rank = GaussJordan(mat,true) ;
    vector<ld> res ;
    for(int row = rank ; row < n ; row++) if(mat[row][m] > EPS) return res ;
    res.resize(rank) ;
    for(int row = 0 ; row < rank ; row++) res[row] = mat[row][m] ;
    return res ;
}

// AOJ0004 連立方程式
int main(){
    for(int i = 0 ; i < 2 ; i++){
        ld a , b , c , d , e , f ;
        cin >> a >> b >> c >> d >> e >> f ;
        vector<vector<ld>> mat(2,vector<ld>(2)) ;
        vector<ld> v(2) ;
        mat[0][0] = a ;
        mat[0][1] = b ;
        mat[1][0] = d ;
        mat[1][1] = e ;
        v[0] = c ;
        v[1] = f ;
        vector<ld> res = Solution(mat,v) ;
        for(int i = 0 ; i < res.size() ; i++) cout << setprecision(10) << res[i] << " " ;
        cout << endl ;
    }
}