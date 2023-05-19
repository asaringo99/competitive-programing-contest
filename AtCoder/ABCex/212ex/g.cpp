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

const int mod = 998244353 ;

ll p ;
ll mp[101010] ;

int main(){
    cin >> p ;
    ll n = p - 1 ;
    vector<ll> vec ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            vec.push_back(i) ;
            if(i * i != n) vec.push_back(n/i) ;
        }
    }
    ll res = 1 ;
    sort(vec.begin(),vec.end()) ;
    int m = vec.size() ;
    for(int i = m - 1 ; i >= 0 ; i--){
        ll mov = n / vec[i] ;
        ll val = mov ;
        for(int j = i + 1 ; j < m ; j++){
            if(vec[j] % vec[i] == 0) val -= mp[j] ;
        }
        mp[i] = val ;
        (res += (mov % mod) * (val % mod) % mod) %= mod ;
    }
    cout << res << endl ;
}