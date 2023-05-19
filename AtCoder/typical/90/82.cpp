#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1;
    }
    return res ;
}

ll llpow(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1;
    }
    return res ;
}

ll f(ll x){
    ll two = powmod(2,mod-2) ;
    return (x % mod) * ((x + 1) % mod) % mod * two % mod ;
}

ll square_sequence(ll x){
    ll res = 0 ;
    for(ll i = 1 ; i <= 19 ; i++){
        if(llpow(10,i) - 1 < x) res += ((f(llpow(10,i)-1) - f(llpow(10,i-1)-1) + mod) * i % mod + mod) % mod ;
        else{
            res += ((f(x) - f(llpow(10,i-1)-1) + mod) * i % mod + mod) % mod ;
            break ;
        }
    }
    return res ;
}

ll L , R ;

int main(){
    cin >> L >> R ;
    cout << (square_sequence(R) - square_sequence(L-1) + mod) % mod << endl ;
}