#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const ll mod = 1000000007 ;
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

// 乱数発生器
random_device rnd ;
mt19937 mt(rnd()) ;
uniform_int_distribution<> rand100(1, 99) ;
const ll r = 0 ;
const ll base = 10007 ;

P R[23][1<<20] ;

inline P f(int n , int k){
    if(n == 1 && k == 0) return P('b' + r , 1) ;
    if(n == 2 && k == 0) return P('a' + r , 1) ;
    if(R[n][k].first > 0) return R[n][k] ;
    if(k % 2 == 0) {
        auto [hash1, digit1] = f(n-1,k/2) ;
        auto [hash2, digit2] = f(n-2,k/4) ;
        ll hash = ((ll)hash1 * powmod(base,digit2) % mod + (ll)hash2) % mod ;
        ll digit = digit1 + digit2 ;
        return R[n][k] = P(hash,digit) ;
    }
    else {
        auto [hash1, digit1] = f(n-2,k/4) ;
        auto [hash2, digit2] = f(n-1,k/2) ;
        ll hash = ((ll)hash1 * powmod(base,digit2) % mod + (ll)hash2) % mod ;
        ll digit = digit1 + digit2 ;
        return R[n][k] = P(hash,digit) ;
    }
}

int n ;
string S ;

int main(){
    // fast_input_output
    cin >> S ;
    if(S == "a"){
        cout << 2 << " " << 0 << endl ;
        return 0 ;
    }
    if(S == "b"){
        cout << 1 << " " << 0 << endl ;
        return 0 ;
    }
    ll shash = 0 ;
    n = S.size() ;
    rep(i,n){
        shash *= base ;
        shash += S[i] + r ;
        shash %= mod ;
    }
    vector<P> res ;
    rrep(i,3,23) rep(j,1<<(i-2)){
        auto [hash,digit] = f(i,j) ;
        if(shash == hash && n == digit) {
            res.push_back(P(i,j)) ;
        }
    }
    auto[x,y] = res[res.size()-1] ;
    cout << x << " " << y << endl ;
}