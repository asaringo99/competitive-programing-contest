#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
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
vector<int> L , R ;
vector<P> S ;
vector<vector<int>> dp ;
int n ;

int rec(int l , int r){
    if(r <= l) return 0 ;
    if(dp[l][r] != -1) return dp[l][r] ;
    set<int> st ;
    rep(i,n+1) st.insert(i) ;
    rep(i,n){
        if(L[i] < l || r < R[i]) continue ;
        auto [x,y] = S[i] ;
        int g = rec(l,x+1) ^ rec(y-1,r) ;
        st.erase(g) ;
    }
    auto it = st.begin() ;
    return dp[l][r] = *it ;
}

void solve(){
    int n_ ;
    cin >> n_ ;
    n = n_ ;
    L.resize(n) ; R.resize(n) ; S.resize(n) ;
    rep(i,n) cin >> L[i] >> R[i] , L[i]-- , S[i] = P(L[i],R[i]) ;
    rep(i,n) rep(j,n) {
        int x = L[i] , y = R[i] ;
        if(L[j] < x && x < R[j]) x = L[j] ;
        if(L[j] < y && y < R[j]) y = R[j] ;
        chmin(S[i].first,x) ;
        chmax(S[i].second,y) ;
    }
    dp.resize(101,vector<int>(101)) ;
    rep(i,101) rep(j,101) dp[i][j] = -1 ;
    int g = rec(0,100) ;
    if(g == 0) cout << "Bob" << endl ;
    else cout << "Alice" << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}