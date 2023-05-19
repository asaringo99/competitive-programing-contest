#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(i,t){
        ll n ;
        cin >> n ;
        ll val = sqrt(n) ;
        ll ans = -1 ;
        if((val - 2) * (val - 2) <= n) ans = val - 2 ;
        if((val - 1) * (val - 1) <= n) ans = val - 1 ;
        if((val) * (val) <= n) ans = val ;
        if((val + 1) * (val + 1) <= n) ans = val + 1 ;
        if((val + 2) * (val + 2) <= n) ans = val + 2 ;
        cout << ans << endl ;
    }
}