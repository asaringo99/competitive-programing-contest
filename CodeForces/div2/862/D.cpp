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
    int q;
    cin >> q;
    ll lef = -1, rig = -1;
    rep(i,q){
        ll t, a, b, n;
        cin >> t >> a >> b;
        if(t == 1){
            cin >> n;
            ll x = (n - 2) * (a - b) + a;
            ll y = (n - 1) * (a - b) + a;
            if(n == 1){
                x = 0;
                y = a;
            }
            if(lef == -1){
                lef = x + 1;
                rig = y;
                // cout << lef << " " << rig << endl;
                cout << 1 << " ";
            }
            else{
                if(min(rig,y) - max(lef,x+1) != 0){
                    chmax(lef,x+1);
                    chmin(rig,y);
                    cout << 1 << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
        }
        if(t == 2){
            if(lef == -1){
                cout << -1 << " ";
                continue;
            }
            ll x = (lef - a) % (a - b) == 0 ? (lef - a) / (a - b) + 1 : (lef - a) / (a - b) + 2;
            if(lef - a < 0) x = 1;
            // cout << n << " " << (n - 1) * (a - b) + a << " "  << x << endl;
            ll s = (x - 1) * (a - b) + a;
            if(rig <= s){
                cout << x << " ";
            }
            else{
                cout << -1 << " ";
            }
        }
    }
    cout << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}