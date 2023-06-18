#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define ptv(v) for(auto u : v) cout << u << " "; cout << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> A(n,0);
    multiset<pair<ll,int>> maxst, minst;
    minst.insert({-1,-1});
    minst.insert({-1,-1});
    maxst.insert({1e18,-1});
    maxst.insert({1e18,-1});
    rep(i,k) maxst.insert({0,i});
    rrep(i,k,n) minst.insert({0,i});
    ll res = 0;
    rep(i,q){
        int x, y;
        cin >> x >> y;
        x--;
        ll a = A[x];
        if(maxst.count({a,x})) {
            res -= a;
            maxst.erase({a,x});
            minst.insert({y,x});
            auto it = minst.end(); it--;
            auto[val, id] = *it;
            minst.erase(it);
            // cout << "k :" << i <<" " << val << endl;
            maxst.insert({val,id});
            res += val;
        }
        if(minst.count({a,x})) {
            minst.erase({a,x});
            minst.insert({y,x});
            auto it = minst.end(); it--;
            auto[val, id] = *it;
            minst.erase(it);

            maxst.insert({val,id});
            res += val;
            auto jt = maxst.begin();
            auto[v,ix] = *jt;
            minst.insert({v,ix});
            maxst.erase(jt);
            res -= v;
        }
        A[x] = y;
        cout << res << endl;
    }
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}