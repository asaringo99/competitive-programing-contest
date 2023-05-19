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

int n , v , c ;
ll V[5050] , W[5050] ;
ll dp[5050][5050] ;

int main(){
    fast_input_output
    cin >> n >> v >> c ;
    rep(i,n) cin >> V[i] >> W[i] ;
    rep(i,n) rep(j,v+1) {
        chmax(dp[i+1][j],dp[i][j]) ;
        if(j+V[i] <= v) chmax(dp[i+1][j+V[i]],dp[i][j]+W[i]+c) ;
        if(j+V[i] <= v) chmax(dp[i+1][j+V[i]],dp[i+1][j]+W[i]) ;
    }
    cout << dp[n][v] << endl ;
}