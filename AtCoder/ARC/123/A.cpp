#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll a , b , c ;

int main(){
    cin >> a >> b >> c ;
    ll val = a -2 * b + c ;
    if(val <= 0) cout << abs(val) << endl ;
    else{
        ll res = val / 2 ;
        if(val % 2 != 0){
            res += 2 ;
        }
        cout << res << endl ;
    }
}