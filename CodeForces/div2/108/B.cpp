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
    ll n, m;
    cin >> n >> m;
    ll sx, sy;
    cin >> sx >> sy;
    int k;
    cin >> k;
    ll res = 0;
    rep(i,k){
        int a, b;
        cin >> a >> b;
        ll lef = 0, rig = 2e9;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2;
            ll nx = sx + mid * a;
            ll ny = sy + mid * b;
            if(0 >= nx || nx > n || 0 >= ny || ny > m) rig = mid;
            else lef = mid;
        }
        sx += lef * a;
        sy += lef * b;
        res += lef;
    }
    pt(res);
}

int main(){
    fast_io
    solve();
}