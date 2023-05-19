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

int t ;

void solve(){
    int n , k ;
    cin >> n >> k ;
    vector<int> A(n) ;
    vector<set<int>> st ;
    rep(i,n) cin >> A[i] ;
    sort(A.begin(),A.end()) ;
    st.resize(n) ;
    rep(i,n){
        rrep(j,1,k+1) st[i].insert(A[i]/j) ;
    }
    int res = 1e9 ;
    rep(i,3001){
        bool ok = true ;
        int maxval = 0 , minval = 1e8 ;
        rep(j,n){
            auto it = st[j].lower_bound(i) ;
            if(it == st[j].end()) {
                ok = false ;
                break ;
            }
            int v = *it ;
            chmax(maxval,v) ;
            chmin(minval,v) ;
        }
        if(ok) chmin(res,maxval-minval) ;
    }
    cout << res << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}