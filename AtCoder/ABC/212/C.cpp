#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
set<ll> A , B ;

int main(){
    cin >> n >> m ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A.insert(a) ;
    }
    rep(i,m){
        ll b ;
        cin >> b ;
        B.insert(b) ;
    }
    A.insert(1e17) ;
    A.insert(-1e17) ;
    B.insert(1e12) ;
    B.insert(-1e12) ;
    ll res = 1e16 ;
    for(ll a : A){
        auto it = B.upper_bound(a) ;
        ll val = *it ;
        res = min(res,abs(a-val)) ;
        it-- ;
        val = *it ;
        res = min(res,abs(a-val)) ;
    }
    for(ll b : B){
        auto it = A.upper_bound(b) ;
        ll val = *it ;
        res = min(res,abs(b-val)) ;
        it-- ;
        val = *it ;
        res = min(res,abs(b-val)) ;
    }
    cout << res << endl ;
}