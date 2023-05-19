#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll n , k ;

int main(){
    cin >> n >> k ;
    ll sum = 0 ;
    int A[n] , B[n] ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n) sum += abs(A[i] - B[i]) ;
    if(sum > k || k % 2 != sum % 2) cout << "No" << endl ;
    else cout << "Yes" << endl ;
}