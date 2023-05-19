#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
ll A[101] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    ll res = 0 ;
    rep(t,300){
        vector<vector<ll>> dp(n+1,vector<ll>(301,0)) ;
        dp[0][0] = 1 ;
        rep(i,n){
            rep(j,301){
                dp[i+1][j] += dp[i][j] ;
                if(t >= A[i] && j+t-A[i] < 301) dp[i+1][j+t-A[i]] += dp[i][j] ;
            }
        }
        res += dp[n][t] ;
        ll sum = upper_bound(A,A+n,0) - lower_bound(A,A+n,0) ;
        res -= sum ;
    }
    cout << res - 1 << endl ;
}