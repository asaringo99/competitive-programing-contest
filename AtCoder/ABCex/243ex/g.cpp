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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

int z ;

vector<ll> dp , S ;

void solve(){
    ll x ;
    cin >> x ;
    ll r = sqrtl(x) ;
    ll y = sqrtl(sqrtl(x)) ;
    ll res = S[y] * (r - y * y + 1) ;
    for(ll w = y - 1 ; w >= 1 ; w--){
        ll val = (w+1) * (w+1) - w * w ;
        res += S[w] * val ;
    }
    cout << res << endl ;
}

int main(){
    fast_input_output
    cin >> z ;
    dp.resize(101010,0) ;
    S.resize(101010,0) ;
    dp[1] = 1 ;
    dp[2] = 1 ;
    dp[3] = 1 ;
    S[1] = 1 ;
    S[2] = 2 ;
    S[3] = 3 ;
    rrep(i,4,101010){
        ll y = sqrtl(i) ;
        dp[i] = S[y] ;
        S[i] = S[i-1] + dp[i] ;
    }
    rep(i,z) solve() ;
}