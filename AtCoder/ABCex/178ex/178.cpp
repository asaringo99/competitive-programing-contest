#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[101010] , B[101010] ;
int SA[101010] , SB[101010] ;

int main(){
    cin >> n ;
    int suma = 0 , sumb = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        A[a]++ ;
    }
    rrep(i,1,n+1) SA[i] = SA[i-1] + A[i] ;
    rep(i,n){
        int b ;
        cin >> b ;
        B[b]++ ;
    }
    rrep(i,1,n+1) SB[i] = SB[i-1] + B[i] ;
    
    rrep(i,1,n+1){
        
    }
}