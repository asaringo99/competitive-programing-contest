#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[1007] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int sum = 0 ;
    rep(i,n){
        if(A[i] > 10) sum += A[i] - 10 ;
    }
    cout << sum << endl ;
}