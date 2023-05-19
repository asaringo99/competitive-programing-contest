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

int n ;
P A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        A[i] = P(a,i) ;
    }
    sort(A,A+n) ;
    set<int> st = {-1,n} ;
    ll res = 0 ;
    rep(i,n){
        P p = A[i] ;
        ll a = p.first , id = p.second ;
        st.insert(id) ;
        auto it = st.lower_bound(id) ;
        ll lef = -1 , rig = n ;
        it++ ;
        rig = *it ;
        it-- ; it-- ;
        lef = *it ;
        res += a * (rig - id) * (id - lef) ;
    }
    cout << res << endl ;
}