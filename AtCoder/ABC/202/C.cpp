#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
int A[100007] , B[100007] , C[100007] ;

int main(){
    memset(A,0,sizeof(A)) ;
    memset(B,0,sizeof(B)) ;
    memset(C,0,sizeof(C)) ;
    cin >> n ;
    map<ll,ll> rem_a , rem_b , rem_c ;
    rep(i,n) {
        int a ;
        cin >> a ;
        rem_a[a]++ ;
    }
    rep(i,n) {
        cin >> B[i] ;
    }
    rep(i,n) {
        int c ;
        cin >> c ;
        c-- ;
        rem_b[B[c]]++ ;
    }
    ll res = 0 ;
    for(int i = 1 ; i <= n ; i++){
        res += rem_a[i] * rem_b[i] ;
    }
    cout << res << endl ;
}