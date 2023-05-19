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

const int mod = 1000000007 ;

int n ;
int C[202020] ;
set<int> G[202020] ;
ll dp[202020] ;

int main(){
    cin >> n ;
    rep(i,n){
        int c ;
        cin >> c ;
        C[i] = c ;
        G[c].insert(i) ;
    }
    dp[0] = 1 ;
    rep(i,n-1){
        int c = C[i] ;
        auto it = G[c].lower_bound(i) ; it++ ;
        int j = *it ;
        if(i + 1 != j && it != G[c].end()) (dp[j] += dp[i]) %= mod ;
        (dp[i+1] += dp[i]) %= mod ;
    }
    cout << dp[n-1] << endl ;
}