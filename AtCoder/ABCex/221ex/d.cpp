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
set<int> st ;
ll A[2020202] ;

int main(){
    int n = 1 << 20 ;
    rep(i,n) st.insert(i) , A[i] = -1 ;
    cin >> q ;
    rep(i,q){
        int t ;
        ll x ;
        cin >> t >> x ;
        ll k = x % n ;
        auto it = st.lower_bound(k) ;
        if(it == st.end()) it = st.lower_bound(0) ;
        if(t == 1) {
            A[*it] = x ;
            st.erase(it) ;
        }
        else cout << A[x%n] << endl ;
    }
}