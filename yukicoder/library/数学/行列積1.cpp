#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
using vec = vector<int> ;
using mat = vector<vec> ;
#define MAX_N (ll)1e4
#define MAX_C (ll)1e4

int n ;

mat mul(mat A , mat B){
    mat C(A.size() , vec(B[0].size())) ;
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < B[0].size() ; j++){
            for(int k = 0 ; k < B.size() ; k++){
                C[i][j] += A[i][k] * B[k][j] ; 
            }
        }
    }
    return C ;
}

mat matm(mat A , mat B){
    mat C(A.size() , vec(B[0].size())) ;
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < B.size() ; j++){
            for(int k = 0 ; k < B[0].size() ; k++){
                C[i][k] += A[i][j] * B[j][k] ;
            }
        }
    }
    return C ;
}


int main(){
    int a , b , c , d , e , f , g , h ;
    cin >> a >> b >> c >> d >> e >> f >> g >> h ;
    mat A(2,vec(2)) ;
    mat B(2,vec(2)) ;
    A[0][0] = a ;
    A[0][1] = b ;
    A[1][0] = c ;
    A[1][1] = d ;
    B[0][0] = e ;
    B[0][1] = f ;
    B[1][0] = g ;
    B[1][1] = h ;
    mat V = matm(A,B) ;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            cout << V[i][j] << " " ;
        }
        cout << endl ;
    }
}