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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll n ;

int main(){
    cin >> n ;
    ll sum = 0 ;
    int m = to_string(n).size() ;
    rrep(i,1,m){
        ll s = powll(10,i-1) - 1 , t = powll(10,i) - 1 ;
        ll u = (t % mod - s + mod) % mod * (t % mod - s + 1 + mod) % mod * powll(2,mod-2) % mod ;
        sum += u ;
        sum %= mod ;
    }
    ll s = powll(10,m-1) - 1 ;
    ll u = (n % mod - s + mod) % mod * (n % mod - s + 1 + mod) % mod * powll(2,mod-2) % mod ;
    sum += u ;
    sum %= mod ;
    cout << sum << endl ;
}