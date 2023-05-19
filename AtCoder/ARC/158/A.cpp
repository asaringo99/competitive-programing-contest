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
    ll x, y, z;
    vector<ll> X(3);
    rep(i,3) cin >> X[i];
    sort(all(X));
    x = X[0];
    y = X[1];
    z = X[2];
    if((x + y + z) % 3 != 0){
        cout << -1 << endl;
        return;
    }
    if(x % 2 != y % 2 || y % 2 != z % 2 || z % 2 != x % 2){
        cout << -1 << endl;
        return;
    }
    if((x + y + z) % 3 != 0){
        cout << -1 << endl;
        return;
    }
    if(x % 2 == 1){
        x--;
        y--;
        z--;
    }
    x /= 2;
    y /= 2;
    z /= 2;
    ll w = (x + y + z) / 3;
    ll res = 0;
    if(w > x) res += w - x;
    if(w > y) res += w - y;
    if(w > z) res += w - z;
    cout << res << endl;
    // ll lef = 0, rig = 4e9;
    // while(rig - lef > 1){
    //     ll mid = (lef + rig) / 2;
    //     ll sum = 0;
    //     sum += mid - x;
    //     sum += mid - y;
    //     sum += mid - z;
    //     if(sum > 0) rig = mid;
    //     else lef = mid;
    // }
    // res = 0;
    // if(lef > x) res += lef - x;
    // if(lef > y) res += lef - y;
    // if(lef > z) res += lef - z;
    // cout << res << endl;
    // cout << rig - x << endl;

}

int main(){
    fast_io
    int n;
    cin >> n;
    rep(i,n) solve();
}