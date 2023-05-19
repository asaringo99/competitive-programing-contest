#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , q ;
set<P> yoko , tate ;

int main(){
    cin >> n >> q ;
    tate.insert(P(n,n)) ;
    yoko.insert(P(n,n)) ;
    ll res = (n - 2) * (n - 2) ;
    rep(i,q){
        int t , x ;
        cin >> t >> x ;
        if(t == 1){
            auto it = tate.lower_bound(P(x,-1)) ;
            P p = *it ;
            yoko.insert(P(p.second,x)) ;
            res -= p.second - 2 ;
        }
        if(t == 2){
            auto it = yoko.lower_bound(P(x,-1)) ;
            P p = *it ;
            tate.insert(P(p.second,x)) ;
            res -= p.second - 2 ;
        }
    }
    cout << res << endl ;
}