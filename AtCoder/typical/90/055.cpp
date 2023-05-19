#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , p , q ;
ll A[105] ;

int main(){
    cin >> n >> p >> q ;
    ll res = 0 ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) rrep(j,i+1,n)  rrep(k,j+1,n) rrep(l,k+1,n) rrep(m,l+1,n) 
    if(A[i] % p * A[j] % p * A[k] % p * A[l] % p * A[m] % p == q) res++ ;
    cout << res << endl ;
}