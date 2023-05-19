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
bool dp[101][10101] ;
ll p[101] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    dp[0][0] = true ;
    rep(i,n) rep(j,10101){
        if(dp[i][j]) dp[i+1][j] |= dp[i][j] ;
        dp[i+1][j+p[i]] |= dp[i][j] ;
    }
    ll sum = 0 ;
    rep(i,10101) if(dp[n][i]) sum++ ;
    cout << sum << endl ;
}