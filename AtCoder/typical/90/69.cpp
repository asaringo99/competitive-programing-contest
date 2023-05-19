#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll n , k ;

ll doubling(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n >> k ;
    if(n <= 3){
        if(n == 1) cout << k << endl ;
        if(n == 2) cout << k * (k - 1) % mod << endl ;
        if(n == 3) cout << k * (k - 1) % mod * (k - 2) % mod << endl ;
        return 0 ;
    }
    ll res = k * (k - 1) % mod * (k - 2) % mod ;
    (res *= doubling(k-2,n-3)) %= mod ;
    cout << res << endl ;
}