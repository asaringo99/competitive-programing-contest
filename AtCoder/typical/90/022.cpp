#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll a , b , c ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> a >> b >> c  ;
    ll cut = gcd(a,gcd(b,c)) ;
    cout << (a + b + c) / cut - 3 << endl ;
}