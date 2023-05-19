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
    ld res = (ld)a * (x - 1) / 2 + (ld)n / x * b ;
    return res ;
}

int main(){
    cin >> n >> s >> t >> a >> b ;
    ll lef = 1 , rig = t ;
    int count = 100 ;
    while(count > 0){
        ll lm = (2 * lef + rig) / 3 , rm = (lef + 2 * rig) / 3 ;
        if(f(lm) > f(rm)) lef = lm ;
        else rig = rm ;
        count-- ;
    }
    ld res = t >= s ? (t - s) * a : LLONG_MAX ;
    rrep(i,lef,rig+1){
        chmin(res,f(i)) ;
    }
    cout << fixed << setprecision(25) << res << endl ;
}