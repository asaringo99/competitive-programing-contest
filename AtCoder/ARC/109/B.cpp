#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

ll n ;

int main(){
    cin >> n ;
    ll t = sqrt((n + 1) * 8 + 1) - 2 ;
    ll tmp ;
    for(ll i = t ; i * i <= (n + 1) * 8 + 1 ; i++) tmp = i ;
    ll ans = n + 1 - (tmp - 1) / 2 ;
    cout << ans << endl ;
}