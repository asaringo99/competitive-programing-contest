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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll n ;

bool f(ll a , ll b){
    ll val = a * a * a + a * a * b + a * b * b + b * b * b ;
    if(val >= n) return true ;
    return false ;
}
ll g(ll a , ll b){
    ll val = a * a * a + a * a * b + a * b * b + b * b * b ;
    return val ;
}

int main(){
    fast_input_output
    cin >> n ;
    ll res = 1e18 , ans = -1 ;
    for(ll a = 0 ; a * a * a <= n ; a++){
        ll k = n - a * a * a ;
        ll lef = -1 , rig = 1000001 ;
        while(rig - lef > 1){
            ll mid = (rig + lef) / 2 ;
            if(f(a,mid)) rig = mid ;
            else lef = mid ;
        }
        res = min(res,g(a,rig)) ;
    }
    cout << res << endl ;
}