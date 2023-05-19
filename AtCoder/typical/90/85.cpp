#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll k ;

int main(){
    cin >> k ;
    ll ans = 0 ;
    for(ll a = 1 ; a * a * a <= k ; a++){
        if(k % a != 0) continue ;
        for(ll b = a ; a * b * b <= k ; b++){
            if(k % (a * b) == 0) ans++ ;
        }
    }
    cout << ans << endl ;
}