#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int S[202020] , T[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> S[i] ; rep(i,n) cin >> T[i] ;
    rep(i,2*n+10) T[(i+1)%n] = min(T[(i+1)%n],T[i%n]+S[i%n]) ;
    rep(i,n) cout << T[i] << endl ;
}