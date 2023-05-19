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

ll n , k ; 
vector<P> A , B ;
vector<ll> vec ;
set<int> st ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n){
        ll a ;
        cin >> a ;
        if(i <  k) A.push_back(P(a,i)) ;
        if(i >= k) B.push_back(P(a,i)) ;
    }
    sort(A.begin(),A.end()) ;
    sort(B.begin(),B.end()) ;
    int q = B.size() - 1 ;
    ll res = 1e16 ;
    rep(i,k) {
        auto [a,p] = A[k-1-i] ;
        while(true){
            if(q < 0) break ;
            auto [b,r] = B[q] ;
            if(b > a) st.insert(r) ;
            else break ;
            q-- ;
        }
        if(st.empty()) continue ;
        auto it = st.begin() ;
        int id = *it ;
        chmin(res,(ll)id - k + 1 + (k - p - 1)) ;
    }
    if(res == 1e16) cout << -1 << endl ;
    else cout << res << endl ;
}