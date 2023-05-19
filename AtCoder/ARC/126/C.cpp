#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll k ;
ll A[303030] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

bool f(ll x){
    ll res = 0 ;
    rep(i,n){
        if(res>1e18) return false;
        res += (x - A[i] % x) ;
    }
    return res <= k ;
}

int main(){
    cin >> n >> k ;
    ll maxval = 0 ;
    rep(i,n) {
        cin >> A[i] ;
        maxval = max(maxval,A[i]) ;
    }
    ll g = 0 ;
    rep(i,n) g = gcd(g,A[i]) ;
    ll res = g ;
    for(int i = maxval / 100 ; i < maxval; i += maxval / 100){
        cout << i << endl ;
        ll lef = i - maxval / 100 , rig = i ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(f(mid)) lef = mid ;
            else rig = mid ;
        }
        res = max(res,lef) ;
    }
    ll lef = maxval , rig = 1e18 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    if(lef == maxval) lef = -1 ;
    cout << max(lef,res) << endl ;
}