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

int t ;

void solve(){
    ll n , m ;
    cin >> n >> m ;
    ll v = powmod(n,m/2) ;
    ll u = powmod(n,m) ;
    ll sv = v * (v + 1) % mod * (2 * v + 1) % mod * powmod(6,mod-2) % mod ;
    ll su = u * (u + 1) % mod * powmod(2,mod-2) % mod ;
    cout << (su - sv + mod) % mod << endl ;
}

int main(){
    fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}