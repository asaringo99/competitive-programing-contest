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

ll n ;
vector<P> vec ;

bool f(ll x){
    rep(i,vec.size()){
        P p = vec[i] ;
        ll v = p.first , ex = p.second ;
        ll u = v ;
        while(u <= x){
            ex -= x / u ;
            u *= v ;
        }
        if(ex > 0) return false ;
    }
    return true ;
}

int main(){
    cin >> n ;
    ll res = 0 ;
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        int ex = 0 ;
        while(n % i == 0){
            n /= i ;
            ex++ ;
        }
        vec.push_back(P(i,ex)) ;
    }
    if(n != 1) vec.push_back(P(n,1)) ;

    ll lef = 0 , rig = 1e18 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}