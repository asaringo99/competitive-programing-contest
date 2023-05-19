#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)


ll n , A[3] ;

int main(){
    cin >> n >> A[0] >> A[1] >> A[2] ;
    sort(A,A+3) ;
    int res = INT_MAX ;
    ll a = A[0] , b = A[1] , c = A[2] ;
    for(int i = 9999 ; i >= 0 ; i--){
        if(i * c > n) continue ;
        for(int j = 9999 ; j >= 0 ; j--){
            if(i * c + b * j > n) continue ;
            ll m = n - (i * c + b * j) ;
            if(m % a == 0){
                int k = m / a ;
                res = min(res,i+j+k) ;
            }
        }
    }
    cout << res << endl  ;
}