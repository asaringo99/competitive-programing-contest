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

void solve(){
    ll x, y;
    cin >> x >> y;
    if(x > y) swap(x,y);
    ll s = sqrt(x);
    ll t = sqrt(y);
    ll g, h;
    ll res = 0;
    if(s * s == x) res += s + s - 1;
    else if(x <= s * (s + 1)) res += s + s, s++;
    else res += s + s + 1, s += 2;
    if(t * t == y) {
        res += t + t - 1;
        res = (t - s <= 0 ? res - t + 1 : res - s + 1);
    }
    else if(y <= t * (t + 1)) {
        res += t + t;
        // cout << t << endl;
        res = (t + 1 - s <= 0 ? res - t : res - s + 1);
    }
    else {
        res += t + t + 1;
        res = (t + 2 - s <= 0 ? res - t - 1 : res - s + 1);
    }
    cout << res << endl;
}

int main(){
    // fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}

