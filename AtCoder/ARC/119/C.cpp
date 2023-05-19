#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
ll A[300007] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A[i] = i % 2 == 0 ? a : -a ;
    }
    map<ll,ll> rem ;
    rem[0]++ ;
    ll sum = 0 , res = 0 ;
    rep(i,n){
        sum += A[i] ;
        res += rem[sum] ;
        rem[sum]++ ;
    }
    cout << res << endl ;
}