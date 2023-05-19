#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , q ;

int main(){
    cin >> n ;
    set<ll> A ;
    A.insert(-10000000000000) ;
    A.insert(10000000000000) ;
    for(int i = 0 ; i < n ; i++){
        ll a ;
        cin >> a ;
        A.insert(a) ;
    }
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        ll b ;
        cin >> b ;
        auto it = A.lower_bound(b) ;
        ll x = *it ;
        it-- ;
        ll y = *it ;
        cout << min(abs(x-b),abs(y-b)) << endl ;
    }
}