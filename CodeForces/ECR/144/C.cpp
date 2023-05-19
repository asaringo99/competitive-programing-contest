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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

const int mod = 998244353 ;

void solve(){
    ll l, r;
    cin >> l >> r;
    ll x = l;
    ll y = 1;
    int cnt = 0;
    while(x <= r){
        x *= 2;
        y *= 2;
        cnt++;
    }
    y /= 2;
    if(y == 1){
        cout << 1 << " " << r - l + 1 << endl;
        return;
    }
    ll res = 0;
    ll lef = l, rig = 2e9;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(mid * y <= r) lef = mid;
        else rig = mid;
    }
    res += rig - l;
    lef = l, rig = 2e9;
    y /= 2;
    y *= 3;
    if(l*y>r){
        cout << cnt << " " << res << endl;
        return;
    }
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(mid * y <= r) lef = mid;
        else rig = mid;
    }
    res += (rig - l) * (cnt - 1);
    res %= mod;
    cout << cnt << " " << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}