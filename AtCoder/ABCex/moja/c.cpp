#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef unsigned long long ll ;
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

ll x , y ;

int main(){
    fast_input_output
    cin >> x >> y ;
    ll m = x / y ;
    ll t = 1 , M = -1 ;
    for(ll i = 1 ; i <= 20 ; i++){
        t *= i ;
        M = i ;
        if(t == m) break ;
    }

    ll n = -1 ;
    for(ll i = M ; i <= 20 ; i++){
        ll val = 1 ;
        for(ll j = 0 ; j < M ; j++) val *= (i - j) ;
        n = i ;
        if(val == x) break ;
    }
    cout << n << " " << M << endl ;
}