#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll L , q ;
set<ll> st ;

int main(){
    cin >> L >> q ;
    st.insert(0) ;
    st.insert(L) ;
    rep(i,q){
        ll c , x ;
        cin >> c >> x ;
        if(c == 1){
            st.insert(x) ;
        }
        if(c == 2){
            auto it = st.upper_bound(x) ;
            ll p = *it ;
            it-- ;
            ll q = * it ;
            cout << p - q << endl ;
        }
    }
}