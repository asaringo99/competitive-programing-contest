#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

const int mod = 1000000007;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if(m == 1){
        cout << 1 << endl;
        return;
    }
    if(n == 1){
        cout << m << endl;
        return;
    }
    if(k == 1 || n < k){
        cout << powmod(m,n) << endl;
        return;
    }
    if(k == n){
        ll res = powmod(m,n/2);
        if(n % 2 == 1) (res *= m) %= mod;
        cout << res << endl;
        return;
    }
    if(k % 2 == 0){
        cout << m << endl;
        return;
    }
    cout << m * m << endl;
}

int main(){
    fast_io
    int z;
    solve();
}