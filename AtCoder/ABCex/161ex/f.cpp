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

int main(){
    cin >> n ;
    if(n == 2){
        cout << 1 << endl ;
        return 0 ;
    }
    ll m = n ;
    ll k = n - 1 ;
    ll res = 1 ;
    for(ll i = 2 ; i * i <= k ; i++){
        if(k % i == 0){
            res++ ;
            if(i * i != k) res++ ;
        }
    }
    vector<ll> vec = {n} ;
    for(ll i = 2 ; i * i <= m ; i++){
        if(m % i == 0){
            vec.push_back(i) ;
            if(i * i != m) vec.push_back(m/i) ;
        }
    }
    rep(i,vec.size()){
        ll s = n ;
        while(s % vec[i] == 0) s /= vec[i] ;
        if(s % vec[i] == 1) res++ ;
    }
    cout << res << endl ;
}