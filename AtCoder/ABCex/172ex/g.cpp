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

ll n ;
unordered_map<ll,ll> mp;
vector<ll> ds , ps ;
map<char,vector<int>> tt ;

int main(){
    cin >> n ;
    n-- ;
    ll p = n ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            ds.push_back(i) ;
            if(i * i != n) ds.push_back(n/i) ;
        }
    }
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        while(n % i == 0) n /= i ;
        ps.push_back(i) ;
    }
    if(n != 1) ps.push_back(n) ;
    sort(ds.begin(),ds.end()) ;
    for(ll d : ds) mp[d] = p / d ;
    for(ll u : ps){
        for(ll d : ds){
            if(d % u == 0) mp[d/u] -= mp[d] ;
        }
    }
    ll res = 1 ;
    for(ll d : ds) (res += mp[d] % mod * ((p/d) % mod) % mod) %= mod ;
    cout << res << endl ;
}