#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m , d ;
int A[202020] , X[101010] ;
int Y[50][101010] ;

void f(){
    int k = 0 ;
    while(k < 45){
        rep(i,n) Y[k+1][i] = Y[k][Y[k][i]] ;
        k++ ;
    }
}

int doubling(int v , int d){
    int k = 0 ;
    while(d > 0){
        if(d & 1) v = Y[k][v] ;
        d >>= 1 ;
        k++ ;
    }
    return v ;
}

int main(){
    cin >> n >> m >> d ;
    rep(i,m) cin >> A[i] , A[i]-- ;
    rep(i,n) X[i] = i ;
    rep(i,m) swap(X[A[i]],X[A[i]+1]) ;
    rep(i,n) Y[0][X[i]] = i ;
    f() ;
    rep(i,n){
        cout << doubling(i,d) + 1 << endl ;
    }
}