#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int q ;
multiset<ll> st;

int main(){
    cin >> q ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            ll x ;
            cin >> x ;
            st.insert(x) ;
        }
        if(t == 2){
            ll x , k ;
            cin >> x >> k ;
            auto it = st.upper_bound(x) ;
            bool ok = true ;
            if(it == st.begin()) ok = false ;
            while(k > 0 && ok){
                k-- ;
                it-- ;
                if(it == st.begin() && k > 0) {
                    ok = false ;
                    break ;
                }
            }
            if(ok) cout << *it << endl ;
            else cout << -1 << endl ;
        }
        if(t == 3){
            ll x , k ;
            cin >> x >> k ;
            k-- ;
            auto it = st.lower_bound(x) ;
            bool ok = true ;
            if(it == st.end()) ok = false ;
            while(k > 0 && ok){
                k-- ;
                it++ ;
                if(it == st.end()){
                    ok = false ;
                    break ;
                }
            }
            if(ok) cout << *it << endl ;
            else cout << -1 << endl ;
        }
    }
}