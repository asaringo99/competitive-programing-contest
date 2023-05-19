#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll n ;


ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1  ;
    }
    return res ;
}

ll XOR[65];

int main(){
    cin >> n;
    rep(i,n){
        ll a;
        cin >> a;
        for(int j = 0 ; j < 60 ; j++) if(a >> j & 1) XOR[j]++;
    }
    ll res = 0;
    for(int i = 0; i < 60; i++){
        (res += (n - XOR[i]) * XOR[i] % mod * powmod(2,i) % mod) %= mod;
    }
    cout << res << endl;
}