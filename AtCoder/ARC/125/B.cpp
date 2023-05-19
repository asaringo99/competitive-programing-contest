#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;
ll n ;

int main(){
    cin >> n ;
    ll res = 0 ;
    for(ll i = 1 ; i * i <= n ; i++){
        ll val = i * i , tmp = n - val ;
        if(tmp < 0) continue ;
        (res += tmp / (2 * i) + 1) %= mod ;
    }
    cout << res << endl ;
}