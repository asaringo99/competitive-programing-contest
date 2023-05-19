#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll a , b , c ;

ll ppow(ll a , ll b){
    ll res = 1 ;
    for(int i = 0 ; i < b ; i++) res *= a ;
    return res ;
}

int main(){
    cin >> a >> b >> c ;
    if(a < ppow(c,b)) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}