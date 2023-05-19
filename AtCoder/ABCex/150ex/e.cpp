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

int n ;
ll C[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    sort(C,C+n) ;
    ll res = 0 ;
    rep(i,n){
        ll p = 1 ;
        if(i > 0){
            (p *= powmod(2,i) * powmod(2,i) % mod) %= mod ;
            p += mod ;
            p %= mod ;
        }
        if(i < n - 1) (p *= (n - i + 1) * powmod(2,n-i-1) % mod * powmod(2,n-i-1) % mod * powmod(2,mod-2) % mod) %= mod ;
        (p *= 2) %= mod ;
        (res += p * C[i] % mod) %= mod ;
    }
    cout << res << endl ;
}