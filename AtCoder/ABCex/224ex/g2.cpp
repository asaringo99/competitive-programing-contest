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

ll n , s , t , a , b ;

ld f(ll x){
    return (ld)n / x * b + (ld)(x - 1) / 2 * a ;
}

int main(){
    cin >> n >> s >> t >> a >> b ;
    ll lef = 1 , rig = t ;
    int count = 0 ;
    while(count < 100){
        ll ml = (2LL * lef + rig) / 3 , mr = (lef + 2 * rig) / 3 ;
        if(f(ml) < f(mr)) rig = mr ;
        else lef = ml ;
        count++ ;
    }
    ld res = 1e18 ;
    int id = -1 ;
    rrep(i,lef,rig+1) {
        if(res > f(i)){
            res = f(i) ;
            id = i ;
        }
    }
    if(t - id + 1 <= s && s <= t) cout << (t - s) * a << endl ;
    else cout << fixed << setprecision(25) << res << endl ;
}