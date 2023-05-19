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

ll n , m ;
ll A[101010] ;
map<ll,ll> mp ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) cin >> A[i] , mp[A[i] % m]++ ;
    int res = 0 ;
    set<ll> st ;
    for(auto it : mp){
        ll a = it.first , c = it.second ;
        if(st.count(a) == 1 || st.count(m-a) == 1) continue;
        st.insert(a) ;
        st.insert(m-a) ;
        if(a == 0) res++ ;
        else if(a + a == m) res++ ;
        else res += max(mp[m-a],mp[a]) ;
    }
    cout << res << endl ;
}