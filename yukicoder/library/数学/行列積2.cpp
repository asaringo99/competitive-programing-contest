#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
using vec = vector<int> ;
using mat = vector<vec> ;
#define MAX_N (ll)1e4
#define mod 10007

int n ;

ll A[MAX_N][MAX_N] ;

vector<vector<ll>> mat(vector<vector<ll>> A , vector<vector<ll>> B){
    vector<vector<ll>> C(A.size(),vector<ll>(B[0].size())) ;
    for(int i = 0 ; i < A.size() ; i++)
        for(int j = 0 ; j < B[0].size() ; j++){
            C[i][j] = 0 ;
            for(int k = 0 ; k < B.size() ; k++){
                C[i][j] += (A[i][k] * B[k][j]) % mod ;
            }
        }
    return C ;
}