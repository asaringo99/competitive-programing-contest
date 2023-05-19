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

int n , k ;
ll S[101010] ;

int main(){
    cin >> n >> k ;
    for(int i = k ; i > 0 ; i--){
        ll s = k / i ;
        S[i] = powmod(s,n) ;
        for(int j = i * 2 ; j <= k ; j += i){
            S[i] -= S[j] ;
            S[i] += mod ;
            S[i] %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,k+1) (res += S[i] * i % mod) %= mod ;
    cout << res << endl ;
}