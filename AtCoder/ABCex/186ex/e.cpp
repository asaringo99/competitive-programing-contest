#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll extgcd(ll a , ll b , ll& x , ll& y){
    if(b == 0){
        x = 1 ; y = 0 ;
        return a ;
    }
    else{
        ll d = extgcd(b , a % b , y , x) ;
        y -=  a / b * x ;
        return d ;
    }
}

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,b%a) ;
}

int t ;

int main(){
    cin >> t ;
    rep(i,t){
        ll n , s , k , x = -1 , y = -1 ;
        cin >> n >> s >> k ;
        ll d = extgcd(n,k,x,y) ;
        cout << x << " " << y << " " << d << endl ;
        // if(s % d == 0) cout << s / d * x << endl ;
        // else cout << -1 << endl ;
    }
}