#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W ;

int main(){
    cin >> H >> W ;
    int row[H] , col[W] , A[H][W] ;
    memset(row,0,sizeof(row)) ;
    memset(col,0,sizeof(col)) ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> A[i][j] ;
            row[i] += A[i][j] ;
            col[j] += A[i][j] ;
        }
    }
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cout << row[i] + col[j] - A[i][j] << " " ;
        }
        cout << endl ;
    }
}