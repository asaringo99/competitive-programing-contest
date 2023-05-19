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

ll n;

int main(){
    fast_io
    cin >> n;
    vector<ll> A(n);
    vector<vector<ll>> D(20,vector<ll>(10,0));
    rep(i,n) cin >> A[i];
    rep(i,n){
        string s = to_string(A[i]);
        reverse(all(s));
        while(s.size()<17) s.push_back('0');
        rep(j,s.size()) {
            D[j][s[j]-'0']++;
        }
    }
    vector<vector<ll>> vec(20);
    ll t = 10;
    rep(k,17){
        rep(i,n) vec[k].push_back(A[i] % t);
        sort(all(vec[k]));
        t *= 10;
    }
    ll res = 0;
    rep(i,n){
        ll k = 10;
        string s = to_string(A[i]);
        reverse(all(s));
        while(s.size()<17) s.push_back('0');
        rep(j,s.size()){
            ll r = k / 10;
            rep(x,10) res += D[j][x] * ((x + (s[j] - '0')) % 10);
            ll v = A[i] % k;
            auto it = lower_bound(all(vec[j]), k - v);
            ll c = it - vec[j].begin();
            res += n - c;
            k *= 10;
            if(v % r == 0) continue;
            if(j > 0){
                ll x = k / 10 - v / r * r - 1;
                ll g = upper_bound(all(vec[j]), x) - it;
                res -= g * 10;
            }
        }
    }
    cout << res << endl;
}