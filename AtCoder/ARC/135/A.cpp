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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll x ;
unordered_map<ll,ll> dp ;

inline ll rec(ll x){
    if(dp[x] != 0) return dp[x] ;
    if(x <= 4) return x ;
    ll y = x / 2 ;
    ll z = x - y ;
    ll a = rec(y) ;
    ll b = rec(z) ;
    dp[y] = a ;
    dp[z] = b ;
    return a % mod * b % mod ;
}

int main(){
    cin >> x ;
    cout << rec(x) << endl ;
    // if(x % 2 & 1){
    //     ll y = x / 2 ; y-- ;
    //     ll res = powmod(2,y) * 3 % mod ;
    //     cout << res << endl ;
    // }
    // else{
    //     ll y = x / 2 ;
    //     cout << powmod(2,y) << endl ;
    // }
}