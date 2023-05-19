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

ll a, b;

vector<ll> f(ll v, ll g){
    vector<ll> vec;
    for(ll x = 1; x * x <= v; x++){
        if(v % x == 0){
            if(x >= g) vec.push_back(x);
            if(x * x != v && (v / x) >= g) vec.push_back(v/x);
        }
    }
    return vec;
}

int main(){
    fast_io
    cin >> a >> b;
    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    if(a > b) swap(a,b);
    ll s = b - a;
    ll g = gcd(a,b);
    vector<ll> vec = f(s,g);
    sort(all(vec));
    ll res = 0;
    int i = 0;
    while(i < vec.size()){
        ll x = vec[i];
        ll nx = 1e18, ms = -1, k = -1;
        for(int j = i + 1; j < vec.size(); j++){
            ll y = vec[j];
            ll val = min(a - a / y * y, b - b / y * y);
            if(val % x == 0 && nx > val / x) {
                nx = val / x;
                k = j;
            }
        }
        if(k == -1){
            res += a / x;
            break;
        }
        res += nx;
        // cout << a << " " << b << " " << nx << " " << x << " " << ms << " " << res << endl;
        a -= nx * x;
        b -= nx * x;
        i = k;
    }
    cout << res << endl;
}