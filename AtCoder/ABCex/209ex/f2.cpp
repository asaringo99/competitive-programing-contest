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
ll H[4040] ;
ll dp[4040][4040] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> H[i] ;
    dp[0][0] = 1 ;
    rrep(i,1,n){
        vector<ll> S(n+1,0) ;
        rep(j,i) S[j+1] = (S[j] + dp[i-1][j]) % mod ;
        rep(j,i+1){
            if(H[i] <= H[i-1]) (dp[i][j] += S[j]) %= mod ;
            if(H[i] >= H[i-1]) (dp[i][j] += (S[i] - S[j] + mod) % mod) %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,n) (res += dp[n-1][i]) %= mod ;
    cout << res << endl ;
}