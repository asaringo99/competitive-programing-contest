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
    ll n;
    cin >> n;
    bool p = true;
    int ok = 0;
    ll res = 1;
    for(ll x = 2; x * x <= n; x++){
        while(n % x == 0){
            p = false;
            n /= x;
            if(ok < 2) res *= x;
            ok++;
        }
    }
    if(n != 1){
        if(ok < 2) res *= n;
        ok++;
    }
    if(p){
        cout << 1 << endl << 0 << endl;
        return;
    }
    if(ok <= 2){
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl << res << endl;
}

int main(){
    fast_io
    solve();
}