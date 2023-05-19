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

int n , x ;
int A[101010] , T[101010] ;
P S[101010] ;
set<int> st ;

int main(){
    fast_input_output
    cin >> n >> x ;
    rep(i,n) st.insert(i) ;
    rep(i,n) cin >> T[i] , T[i]-- ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) S[i] = P(A[i],T[i]) ;
    sort(S,S+n,greater<P>()) ;
    int res = 0 ;
    rep(i,n){
        if(x <= 0){
            cout << res << endl ;
            return 0 ;
        }
        auto [val,t] = S[i] ;
        auto it = st.upper_bound(t) ;
        if(it == st.begin()) continue;
        it-- ;
        st.erase(it) ;
        x -= val ;
        res++ ;
    }
    if(x <= 0){
        cout << res << endl ;
        return 0 ;
    }
    cout << -1 << endl ;
}