#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ld,ld> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
P X[202020] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll x , y ;
        cin >> x >> y ;
        if(x != 1) X[i] = P((ld)y/(x-1),(ld)(y-1)/x) ;
        if(x == 1) X[i] = P(1e18,(ld)(y-1)/x) ;
    }
    sort(X,X+n) ;
    int ans = 0 ;
    ld c = -1 ;
    rep(i,n){
        P p = X[i] ;
        ld a = p.first , b = p.second ;
        if(b < c) continue ;
        c = a ;
        ans++ ;
    }
    cout << ans << endl ;
}