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
    ll res = 0;
    rrep(i,2,1001){
        ll N = n;
        ll val = 0;
        ll j = 1;
        bool ok = true;
        while(N > 0){
            ll d = N % i;
            if(d > 1) ok = false;
            val += j * d;
            j *= i;
            N /= i;
        }
        if(ok) res++;
    }
    rep(S,(1<<6)){
        vector<bool> vec(6,false);
        rep(i,6) if(S >> i & 1) vec[i] = true;
        ll lef = 1001, rig = n+1;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2;
            ll val = 0;
            ll dig = 1;
            bool fin = false;
            rep(i,6) {
                if(fin) continue;
                if(vec[i]) val += dig;
                if((ld)dig * mid >= 2e18) {
                    fin = true;
                    continue;
                }
                dig *= mid;
            }
            if(n == val) {
                res++;
                break;
            }
            if(val < n) lef = mid;
            else rig = mid;
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    int n;
    cin >> n;
    rep(i,n) solve();
}