#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<ll> R , G , B ;

ll f(vector<ll> X , vector<ll> Y , vector<ll> Z){
    ll x = X.size() , y = Y.size() , z = Z.size() ;
    ll res = 1e17 ;
    rep(i,y){
        ll s = Y[i] ;
        auto it = lower_bound(Z.begin(),Z.end(),s) ;
        res = min(res,abs(s-*it)) ;
        it-- ;
        res = min(res,abs(s-*it)) ;
    }
    ll v = 1e17 ;
    if(x > 0) rep(i,y){
        ll s = Y[i] ;
        auto it = lower_bound(X.begin(),X.end(),s) ;
        v = min(v,abs(s-*it)) ;
        it-- ;
        v = min(v,abs(s-*it)) ;
    }
    ll u = 1e17 ;
    if(x > 0) rep(i,z){
        ll s = Z[i] ;
        auto it = lower_bound(X.begin(),X.end(),s) ;
        u = min(u,abs(s-*it)) ;
        it-- ;
        u = min(u,abs(s-*it)) ;
    }
    res = min(res,u+v) ;
    return res ;
}

int main(){
    cin >> n ;
    rep(i,2*n){
        ll a ; char c ;
        cin >> a >> c ;
        if(c == 'R') R.push_back(a) ;
        if(c == 'G') G.push_back(a) ;
        if(c == 'B') B.push_back(a) ;
    }
    int r = R.size() , g = G.size() , b = B.size() ;
    if(r % 2 == 0 && g % 2 == 0 && b % 2 == 0){
        cout << 0 << endl ;
        return 0 ;
    }
    R.push_back(-1e16) ; R.push_back(1e16);
    G.push_back(-1e17) ; G.push_back(1e17);
    B.push_back(-1e18) ; B.push_back(1e18);
    sort(R.begin(),R.end()) ;
    sort(G.begin(),G.end()) ;
    sort(B.begin(),B.end()) ;
    ll res = 1e18 ;
    if(r % 2 == 0) res = min({f(R,G,B),f(R,B,G)}) ;
    if(g % 2 == 0) res = min({f(G,R,B),f(G,B,R)}) ;
    if(b % 2 == 0) res = min({f(B,G,R),f(B,R,G)}) ;
    cout << res << endl ;
}