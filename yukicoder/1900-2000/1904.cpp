#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ; 
map<ll,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        mp[a]++ ;
    }
    ll res = 1 ;
    for(auto it : mp){
        rep(i,it.second) res *= (n - i) ;
        rep(i,it.second) res /= (i + 1) ;
        n -= it.second ;
    }
    cout << res << endl ;
}