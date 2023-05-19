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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}


int n ;
string T ;
vector<int> digit ;
ll S[202020] ;

int main(){
    cin >> T ;
    n = T.size() ;
    rep(i,n) digit.push_back(T[i] - '0') ;
    ll res = 0 ;
    rep(i,n) S[i+1] = (S[i] + digit[i]) % mod ;
    rrep(i,1,n+1){
        if(i < n) (res += S[n-i] * powmod(10,i-1) % mod * powmod(2,n-1-i)) %= mod ;
        (res += digit[n-i] * powmod(10,i-1) % mod * powmod(2,n-i) % mod) %= mod ;
    }
    cout << res << endl ;
}