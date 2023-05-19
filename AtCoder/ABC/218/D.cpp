#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<P,bool> mp ;
P X[2020] ;

int main(){
    cin >> n ;
    rep(i,n){
        cin >> X[i].first >> X[i].second ;
        mp[X[i]] = true ;
    }
    sort(X,X+n) ;
    ll res = 0 ;
    rep(i,n) rep(j,n){
        int x = X[i].first , y = X[i].second , t = X[j].first , s = X[j].second ;
        if(mp[P(x,s)] && mp[P(t,y)] && x != t && y != s) res++ ;
    }
    cout << res / 4 << endl ;
}