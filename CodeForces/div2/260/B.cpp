#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 5 ;

string S ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> S ;
    int n ;
    if(S.size() == 1) n = S[0] - '0' ;
    else n = (S[S.size() - 2] - '0') * 10 + (S[S.size() - 1] - '0') ;
    n %= 4 ;
    ll res = (powmod(1,n) + powmod(2,n) + powmod(3,n) + powmod(4,n)) % 5 ;
    cout << res << endl ;
}