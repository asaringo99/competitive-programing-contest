#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> P(n);
    rep(i,n) cin >> P[i];
    sort(all(P));
    ll res = 0;
    ll pos = -1;
    rep(i,n-1){
        ll l = P[i];
        ll r = P[i+1];
        ll lef = l + 1, rig = r - 1;
        int cnt = 0;
        while(cnt < 150){
            ll lm = (lef * 2 + rig) / 3, rm = (lef + 2 * rig) / 3;
            ll sum_l = 1, sum_r = 1;
            if(i < k - 1){
                sum_l += lm;
                sum_r += rm;
            }
            else{
                sum_l += lm - (P[i - k + 1] + lm - 1) / 2;
                sum_r += rm - (P[i - k + 1] + rm - 1) / 2;
            }
            if(i + k >= n){
                sum_l += m - lm;
                sum_r += m - rm;
            }
            else{
                sum_l += (P[i + k] + lm - 1) / 2 - lm;
                sum_r += (P[i + k] + rm - 1) / 2 - rm;
            }
            if(sum_l > sum_r) {
                rig = rm;
                if(sum_l > res){
                    pos = lm;
                    res = sum_l;
                }
            }
            else {
                lef = lm;
                if(sum_r > res){
                    pos = rm;
                    res = sum_r;
                }
            }
            cnt++;
        }
    }
    cout << res << " " << pos << endl;
}

int main(){
    fast_io
    solve();
}