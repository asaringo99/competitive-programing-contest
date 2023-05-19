#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll n , m ;

int main(){
    fast_input_output
    cin >> n >> m ;
    if(m <= 100){
        vector<int> vec(202,0) ;
        rep(i,m){
            rep(s,40) if(n >> s & 1) vec[i+s]++ ;
        }
        ll res = 0 ;
        rep(i,200) (res += (vec[i] % 2) * powmod(2,i)) %= mod ;
        cout << res << endl ;
        return 0 ;
    }
    m-- ;
    ll t = m - 40 ;
    ll b = 0 ;
    rep(i,40) if(n >> i & 1) b++ ;
    ll sum = 0 ;
    sum += (b % 2) * (powmod(2,t) - 1) * powmod(2,40) % mod ;
    sum %= mod ;
    vector<int> vec(202,0) , arr(202,0) ;
    rep(i,40){
        rep(s,40) if(n >> s & 1) vec[i+s]++ ;
    }
    rep(i,40) (sum += (vec[i] % 2) * powmod(2,i) % mod) %= mod ;
    rep(i,40){
        rep(s,40) if(n >> s & 1) arr[s]++ ;
        n /= 2 ;
    }
    rep(i,40) (sum += (arr[i] % 2) * powmod(2,i+m) % mod) %= mod ;
    cout << sum << endl ;
}