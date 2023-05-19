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
    bool swh = false ;
    rep(i,S.size()){
        if(S[i] == '/') swh = true ;
        else if(!swh){
            x *= 10 ;
            x += S[i] - '0' ;
        }
        else{
            y *= 10 ;
            y += S[i] - '0' ;
        }
    }
    ll X = x / gcd(x,y) , Y = y / gcd(x,y) ;
    x = X ;
    y = Y ;
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