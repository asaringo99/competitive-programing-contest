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
    vector<int> C(2), R(2), D(2);
    rep(i,2) cin >> R[i];
    rep(i,2) cin >> C[i];
    rep(i,2) cin >> D[i];
    rrep(x,1,10) rrep(y,1,10) rrep(s,1,10) rrep(t,1,10) {
        if(x + y != R[0]) continue;
        if(s + t != R[1]) continue;
        if(x + s != C[0]) continue;
        if(y + t != C[1]) continue;
        if(x + t != D[0]) continue;
        if(y + s != D[1]) continue;
        if(x == y || x == s || x == t || y == s || y == t || s == t) continue;
        cout << x << " " << y << endl;
        cout << s << " " << t << endl;
        return;
    }
    cout << -1 << endl;
}

int main(){
    fast_io
    solve();
}