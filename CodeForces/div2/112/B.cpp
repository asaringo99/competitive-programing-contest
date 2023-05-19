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
    ll n, k;
    cin >> n >> k;
    ll lef = 0, rig = 1e14;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        ll sum = 0;
        ll v = mid;
        ll t = 1;
        while(1){
            if(v / t == 0) break;
            sum += v / t;
            t *= k;
        }
        if(sum >= n) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}

int main(){
    fast_io
    solve();
}