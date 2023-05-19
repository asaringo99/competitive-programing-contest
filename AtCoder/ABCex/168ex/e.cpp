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

const int mod = 1000000007 ;

ll powmod(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

int n ;
map<P,ll> mp ;
map<P,bool> use ;

int main(){
    cin >> n ;
    ll sum = 0 ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        if(a == 0 && b == 0){
            sum++ ;
            continue ;
        }
        if(a < 0){
            a *= -1 ;
            b *= -1 ;
        }
        if(a == 0) b = abs(b) ;
        ll g = gcd(abs(a),abs(b)) ;
        mp[P(a/g,b/g)]++ ;
    }
    ll res = 1 ;
    for(auto it : mp){
        P p = it.first ;
        if(use[p]) continue ;
        ll x = p.first , y = p.second ;
        ll s = -y , t = x ;
        if(s < 0){
            s *= -1 ;
            t *= -1 ;
        }
        if(s == 0) t = abs(t) ;
        use[P(x,y)] = true ;
        use[P(s,t)] = true ;
        (res *= (powmod(2,mp[P(x,y)]) + powmod(2,mp[P(s,t)]) - 1 + mod) % mod) %= mod ;
    }
    cout << (res - 1 + sum + mod) % mod << endl ;
}