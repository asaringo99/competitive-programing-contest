#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> S ;
    ll x = 0 , y = 0 ;
    int i = 0 ;
    while(S[i] != '/'){
        x = 10 * x + (S[i] - '0') ;
        i++ ;
    }
    i++ ;
    while(i < S.size()){
        y = 10 * y + (S[i] - '0') ;
        i++ ;
    }
    ll g = gcd(x,y) ;
    x /= g ;
    y /= g ;
    ll lef = 2 * x / y ;
    ll rig = 2 * x / y + 1 ;
    bool ok = false ;
    if(lef > 0 && lef % y == 0){
        cout << lef << " " << (lef * (lef + 1) / 2 - lef / y * x) << endl ;
        ok = true ;
    }
    if(rig > 0 && rig % y == 0){
        cout << rig << " " << (rig * (rig + 1) / 2 - rig / y * x) << endl ;
        ok = true ;
    }
    if(!ok) cout << "Impossible" << endl ;
}