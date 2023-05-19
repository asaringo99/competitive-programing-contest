#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll a , b ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> a >> b ;
    ll g = gcd(a,b) ;
    a /= g ;
    if(a > 1000000000000000000LL / b) cout << "Large" << endl ;
    else cout << a * b << endl ;
}