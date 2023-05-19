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

int n , mod ;
string S ;
ll A[201010] ;
unordered_map<ll,ll> mp ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n >> mod >> S ;
    reverse(S.begin(),S.end()) ;
    if(mod == 2){
        ll res = 0 ;
        rep(i,n) if((S[i] - '0') % 2 == 0) res += n - i ;
        cout << res << endl ;
        return 0 ;
    }
    if(mod == 5){
        ll res = 0 ;
        rep(i,n) if((S[i] - '0') % 5 == 0) res += n - i ;
        cout << res << endl ;
        return 0 ;
    }
    ll res = 0 , sum = 0 ;
    mp[0]++ ;
    rep(i,n){
        (sum += powmod(10,i) * (S[i] - '0') % mod) %= mod ;
        res += mp[sum] ;
        mp[sum]++ ;
    }
    cout << res << endl ;
}