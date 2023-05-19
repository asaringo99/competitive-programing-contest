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

const int mod = 998244353 ;

int n , s ;
int A[3030] ;
ll dp[3030][3030] ;

int main(){
    cin >> n >> s ;
    rep(i,n) cin >> A[i] ;
    dp[0][0] = 1 ;
    rep(i,n){
        rep(j,s+1){
            (dp[i+1][j] += dp[i][j]) %= mod ;
            if(j + A[i] > s) continue ;
            (dp[i+1][j+A[i]] += dp[i][j]) %= mod ;
        }
        dp[i+1][0]++ ;
    }
    ll res = 0 ;
    rep(i,n+1) (res += dp[i][s]) %= mod ;
    cout << res << endl ;
}