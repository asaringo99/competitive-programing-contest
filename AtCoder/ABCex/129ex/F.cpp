#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll L , A , B , M ;

template<typename T>
struct matrix{

    vector<vector<T>> calculation(vector<vector<T>> A , vector<vector<T>> B){
        int a = A.size() , b = B.size() ;
        vector<vector<T>> C(a,vector<T>(b,0)) ;
        for(int i = 0 ; i < a ; i++){
            for(int j = 0 ; j < b ; j++){
                string S = "" ;
                for(int k = 0 ; k < b ; k++){
                    S += to_string(A[i][k] * B[k][j]) ;
                }
                T val = 0 ;
                for(int k = 0 ; k < S.size() ; k++) (val += S[S.size() - 1 - k] * pow(10,k)) %= M ;
                C[i][j] = val ;
            }
        }
        return C ;
    }

    T powmat(T n , vector<vector<T>> A , vector<vector<T>> B){
        while(n > 0){
            if(n & 1) B = calculation(A,B) ;
            A = calculation(A,A) ;
            n >>= 1 ;
        }
        return B[0][0] ;
    }
};

int main(){
    cin >> L >> A >> B >> M ;
    matrix<ll> mtx ;
    vector<vector<ll>> aa(2,vector<ll>(2)) ;
    vector<vector<ll>> bb(1,vector<ll>(2)) ;
    bb[0][0] = A + B ;
    bb[0][1] = A ;
    aa[0][0] = 1 ;
    aa[0][1] = 1 ;
    aa[1][0] = 1 ;
    aa[1][1] = 0 ;
    cout << mtx.powmat(L,aa,bb) << endl ;
}