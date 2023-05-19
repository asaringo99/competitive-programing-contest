#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
vector<P> X ;

int main(){
    cin >> n >> q ;
    ll minxpy = INT_MAX , minxmy = INT_MAX , maxxpy = -INT_MAX , maxxmy = -INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        ll x , y ;
        cin >> x >> y ;
        X.push_back(P(x,y)) ;
        minxpy = min(minxpy,x+y) ;
        minxmy = min(minxmy,x-y) ;
        maxxpy = max(maxxpy,x+y) ;
        maxxmy = max(maxxmy,x-y) ;
    }
    rep(i,q){
        int v ;
        cin >> v ;
        v-- ;
        ll x = X[v].first , y = X[v].second ;
        ll res = -1 ;
        ll val1 = x + y , val2 = x - y ;
        cout << max(max(val1-minxpy,maxxpy-val1),max(val2-minxmy,maxxmy-val2)) << endl ;
    }
}