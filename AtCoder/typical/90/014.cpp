#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    ll A[n] , B[n] ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    sort(A,A+n) ;
    sort(B,B+n) ;
    ll res = 0 ;
    rep(i,n){
        res += abs(A[i] - B[i]) ;
    }
    cout << res << endl ;
}