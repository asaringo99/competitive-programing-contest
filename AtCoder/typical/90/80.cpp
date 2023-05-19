#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , d ;

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

ll A[25] ;

int main(){
    cin >> n >> d ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rrep(S,1,1<<n){
        ll flag = 0 , count = 0 , num = d ;
        rep(j,n) if(S >> j & 1){
            flag |= A[j] ;
            count++ ;
        }
        rep(j,d) if(flag >> j & 1) num-- ;
        if(count % 2 == 1) res += powll(2,num) ;
        if(count % 2 == 0) res -= powll(2,num) ;
    }
    cout << powll(2,d) - res << endl ;
}