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

const int mod = 998244353 ;

int n ;
int p[202020] , q[202020] , R[202020] ;
bool used[202020] ;

ll f(int m){
    vector<vector<ll>> dp(m+1,vector<ll>(2,0)) ;
    dp[0][0] = 1 ;
    rep(i,m-1){
        (dp[i+1][0] += dp[i][0]) %= mod ;
        (dp[i+1][1] += dp[i][0]) %= mod ;
        (dp[i+1][0] += dp[i][1]) %= mod ;
    }
    ll res = dp[m-1][0] + dp[m-1][1] * 2 ;
    res %= mod ;
    return res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> p[i] , p[i]-- ;
    rep(i,n) cin >> q[i] , q[i]-- ;
    rep(i,n){
        R[p[i]] = q[i] ;
    }
    ll res = 1 ;
    rep(i,n){
        if(used[i]) continue ;
        int v = R[i] , count = 1 ;
        while(v != i){
            used[v] = true ;
            v = R[v] ;
            count++ ;
        }
        res *= f(count) ;
        res %= mod ;
    }
    cout << res << endl ;
}