#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

int main(){
    cin >> n ;
    ll C[n][n] ;
    ll mgn[n] ;
    ll B[n] , A[n] ;
    mgn[0] = 0 ;
    ll sml = INT_MAX ;
    bool ok = true ;
    for(int i = 0 ; i < n ; i++){
        bool add = false ;
        for(int j = 0 ; j < n ; j++){
            cin >> C[i][j] ;
            if(j == 0 && sml >= C[i][j]) {
                add = true ;
                sml = C[i][j] ;
            }
            if(add){
                B[j] = C[i][j] ;
            }
            if(i == 0 && j > 0){
                mgn[j] = C[i][j] - C[i][j-1] ;
            }
            else if(j > 0){
                if(C[i][j] - C[i][j-1] != mgn[j]) ok = false ;
            }
        }
    }
    if(!ok) {
        NO ;
        return 0 ;
    }
    YES ;
    for(int i = 0 ; i < n ; i++){
        A[i] = C[i][0] - B[0] ;
    }
    for(int i = 0 ; i < n ; i++) cout << A[i] << " " ;
    cout << endl ;
    for(int i = 0 ; i < n ; i++) cout << B[i] << " " ;
    cout << endl ;
}