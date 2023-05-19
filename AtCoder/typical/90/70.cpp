#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll X[100007] , Y[100007] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    sort(X,X+n) ;
    sort(Y,Y+n) ;
    ll cx = X[n/2] , cy = Y[n/2] ;
    ll res = 0 ;
    rep(i,n) res += abs(X[i] - cx) + abs(Y[i] - cy) ;
    cout << res << endl ;
}