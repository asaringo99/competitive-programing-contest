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

void solve(){
    int n;
    cin >> n;
    ll minval = 4e18;
    ll maxval = 0;
    for(ll i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        ll s = i;
        for(ll j = 1; j * j <= n / i; j++){
            if((n/i) % j != 0) continue;
            ll t = j;
            ll u = n/i/j;
            chmin(minval,(s+2)*(t+2)*(u+1));
            chmin(minval,(s+1)*(t+2)*(u+2));
            chmin(minval,(s+2)*(t+1)*(u+2));
            chmax(maxval,(s+2)*(t+2)*(u+1));
            chmax(maxval,(s+1)*(t+2)*(u+2));
            chmax(maxval,(s+2)*(t+1)*(u+2));
        }
    }
    cout << minval - n << " " << maxval - n << endl;
}

int main(){
    fast_io
    solve();
}