#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll x , y , a , b , c ;
ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> x >> y >> a >> b >> c ;
    bool ok = false ;
    rep(i,2) rep(j,2) rep(k,2){
        ll X = x , Y = y ;
        ll s = a % x == 0 ? a / x : a / x + 1 ;
        ll t = b % x == 0 ? b / x : b / x + 1 ;
        ll u = c % x == 0 ? c / x : c / x + 1 ;
        if(i == 0){
            s = a % x == 0 ? a / x : a / x + 1 ;
            y -= s ;
        }
        else{
            s = a % y == 0 ? a / y : a / y + 1 ;
            x -= s ;
        }

        if(j == 0){
            t = b % x == 0 ? b / x : b / x + 1 ;
            y -= t ;
        }
        else{
            t = b % y == 0 ? b / y : b / y + 1 ;
            x -= t ;
        }

        if(k == 0){
            u = a % x == 0 ? c / x : c / x + 1 ;
            y -= u ;
        }
        else{
            u = a % y == 0 ? c / y : c / y + 1 ;
            x -= u ;
        }
        if(x >= 0 && y >= 0){
            cout << "Yes" << endl ;
            return 0 ;
        }
    }
    cout << "No" << endl ;
}