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

string S ;
ll imos[202020] ;
vector<int> digit ;

int main(){
    cin >> S ;
    int n = S.size() ;
    rep(i,n) digit.push_back(S[i] - '0') ;
    ll res = 0 ;
    rep(i,n){
        res += powmod(10,n-1-i) * digit[i] % mod * powmod(2,i) % mod ;
        res %= mod ;
        if(i == n - 1) break ;
        imos[i] = powmod(2,i) * digit[i] % mod * powmod(10,n-2-i) % mod ;
    }
    rep(i,n-1){
        res += imos[i] ;
        res %= mod ;
        imos[i+1] += imos[i] * 2 % mod * powmod(10,mod-2) % mod ;
        imos[i+1] %= mod ;
    }
    cout << res << endl ;
}