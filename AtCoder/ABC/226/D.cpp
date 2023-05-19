#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b);
}

set<P> st ;

ll X[505] , Y[505] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(i,n) rep(j,n){
        if(i == j) continue;
        bool bx = true, by = true;
        ll dx = X[j] - X[i] , dy = Y[j] - Y[i];
        ll g = gcd(abs(dx),abs(dy));
        dx = dx / g;
        dy = dy / g;
        P p = P(dx,dy);
        st.insert(p);
    }
    cout << st.size() << endl;
}