#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n , q ;
set<int> st ;
map<int,ll> mp ;

int main(){
    fast_input_output
    cin >> q ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            int x ;
            cin >> x ;
            mp[x]++ ;
            st.insert(x) ;
        }
        if(t == 2){
            int x , c ;
            cin >> x >> c ;
            int val = min(mp[x],(ll)c) ;
            mp[x] -= val ;
            if(mp[x] == 0) st.erase(x) ;
        }
        if(t == 3){
            auto it = st.begin() ;
            auto jt = st.end() ; jt-- ;
            cout << (*jt - *it) << endl ;
        }
    }
}