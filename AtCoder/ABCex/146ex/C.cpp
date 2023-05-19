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

ll a , b , x ;

int main(){
    cin >> a >> b >> x ;
    ll res = 0 ;
    ll lef = 0 , rig = 1000000001LL ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(a * mid + b * to_string(mid).size() <= x) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}