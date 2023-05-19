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

ll n , k , m ;
vector<P> vec ;
map<ll,ll> mp ;

int main(){
    cin >> n >> k >> m ;
    for(ll i = 2 ; i * i <= m ; i++){
        if(m % i != 0) continue ;
        int ex = 0 ;
        while(m % i == 0){
            m /= i ;
            ex++ ;
        }
        vec.push_back(P(i,ex)) ;
    }
    if(m != 1) vec.push_back(P(m,1)) ;
    for(P p : vec){
        ll v = p.first ;
        while(n >= v){
            ll r = n / v , l = (n - k) / v + k / v ;
            mp[p.first] += r - l ;
            v *= p.first ;
        }
    }
    ll res = 1e18 ;
    for(P p : vec){
        ll v = p.first , cnt = p.second ;
        res = min(res,mp[p.first]/cnt) ;
    }
    cout << res << endl ;
}