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
set<ll> st ;
map<ll,int> mp ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        st.insert(a) ;
        mp[a]++ ;
    }
    ll res = 0 ;
    st.insert(-1) ;
    for(auto it = st.end() ; it != st.begin() ; it--){
        if(it == st.end()) continue ;
        ll a = *it ;
        ll v = 1 ;
        while(v < a) v *= 2 ;
        v -= a ;
        if(v == 0) res += mp[a] / 2 ;
        else{
            ll x = min(mp[a],mp[v]) ;
            res += x ;
            mp[v] -= x ;
        }
    }
    cout << res << endl ;
}