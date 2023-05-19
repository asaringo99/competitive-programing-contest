#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
ll A[100007] , S[100007] ;

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i] ;
    ll mag = 0 ;
    rep(i,n-1){
        mag += abs(A[i] - A[i+1]) ;
        S[i] = A[i+1] - A[i] ;
    }
    rep(i,q){
        ll l , r , v ;
        cin >> l >> r >> v ;
        l-- ;
        r-- ;
        if(l != 0){
            S[l-1] += v ;
            mag += abs(S[l-1]) - abs(S[l-1] - v) ;
        }
        if(r != n-1){
            S[r] -= v ;
            mag += abs(S[r]) - abs(S[r] + v) ;
        }
        cout << mag << endl ;
    }
}