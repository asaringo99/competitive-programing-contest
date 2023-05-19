#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll k ;
string A , B ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> k ;
    cin >> A >> B ;
    ll a = 0 , b = 0 ;
    int an = A.size() , bn = B.size() ;
    rep(i,an){
        a += (A[an - 1 - i] - '0') * powmod(k,i) ;
    }
    rep(i,bn){
        b += (B[bn - 1 - i] - '0') * powmod(k,i) ;
    }
    cout << a * b << endl ;
}