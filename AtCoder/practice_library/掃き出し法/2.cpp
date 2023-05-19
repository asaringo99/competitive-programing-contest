#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const ld ESP = 1e-10 ;

struct Matrix{
    vector<vector<ld>> mat ;
    Matrix(int n , int m , ld x = 0) : mat(n,vector<ld>(m,x)) {}
    size_t size_col() { return mat[0].size() ; }
    size_t size_row() { return mat.size() ; }
    inline vector<ld>& operator [] (int i) {return mat[i] ; }
};

int GaussJordan(Matrix mat , bool is_extended = true){
    int rank = 0 , n = mat.size_row() , m = mat.size_col() ;
    for(int col = 0 ; col < m ; col++){
        if(col == m - 1 && is_extended) continue ;
        int pivot = -1 ;
        ld e = ESP ;
        for(int row = rank ; row < n ; row++){
            if(abs(mat[row][col]) > e){
                e = abs(mat[row][col]) ;
                pivot = row ;
            }
        }
        if(pivot == -1) continue ;
        swap(mat[pivot],mat[rank]) ;
        ld fac = mat[rank][col] ;
        for(int c = 0 ; c = m ; c++) mat[rank][c] /= fac ;
        for(int row = 0 ; row < n ; row++){
            if(row == rank || abs(mat[row][col]) < ESP) continue ;
            ld gac = mat[row][col] ;
            for(int c = 0 ; c < m ; c++) mat[row][c] -= mat[rank][c] * gac ;
        }
        rank++ ;
    }
    return rank ;
}