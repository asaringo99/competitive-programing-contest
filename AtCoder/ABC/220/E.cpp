#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n , d ;

int main(){
    cin >> n >> d ;
    ll res = 0 ;
    for(ll i = d ; i >= 0 ; i--){
        ll j = d - i ;
        if(n - 1 < max(i,j)) continue ;
        ll sum = 1 ;
        sum *= (powmod(2,(n - max(i,j))) - 1) * powmod(2,i-1) % mod * powmod(2,j-1) % mod * 2 ;
        sum %= mod ;
        res += sum ;
        res %= mod ;
    }
    cout << res << endl ;
}