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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n , m ;
ll dp[2020][2020] , S[20220]  ;
int A[2020] , B[2020] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,m) cin >> B[i] ;
    dp[0][0] = 1 ;
    rrep(i,1,n+1){
        S[0] = 1 ;
        rrep(j,1,m+1){
            S[j] = (S[j-1] + dp[i-1][j]) % mod ;
        }
        dp[i][0] = dp[i-1][0] ;
        rrep(j,1,m+1){
            dp[i][j] = dp[i-1][j] ;
            if(A[i-1] == B[j-1]) dp[i][j] = S[j] ;
        }
    }
    ll res = 0 ;
    rep(i,m+1) (res += dp[n][i]) %= mod ;
    cout << res << endl ;
}