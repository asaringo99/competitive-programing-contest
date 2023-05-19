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

int z ;
int dp[101][101] ;
int n ;
vector<int> L , R ;

inline int rec(int l , int r){
    if(dp[l][r] != -1) return dp[l][r] ;
    set<int> st ;
    rep(i,n+1) st.insert(i) ;
    rep(i,n){
        if(L[i] < l || r < R[i]) continue ;
        int g = (rec(l,L[i]+1) ^ rec(R[i]-1,r)) ;
        st.erase(g) ;
    }
    auto it = st.begin() ;
    return dp[l][r] = *it ;
}

void solve(){
    cin >> n ;
    L.resize(n) ;
    R.resize(n) ;
    rep(i,n) cin >> L[i] >> R[i] , L[i]-- ;
    rep(i,101) rep(j,101) dp[i][j] = -1 ;
    int res = rec(0,100) ;
    if(res == 0) cout << "Bob" << endl ;
    else cout << "Alice" << endl ;
}

int main(){
    cin >> z ;
    rep(i,z) solve() ;
}