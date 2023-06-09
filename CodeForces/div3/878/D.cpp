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

int z ;

bool f(ll x, vector<ll> &A){
    ll lf = A[0];
    auto it = upper_bound(all(A), lf + 2 * x);
    if(it == A.end()) return true;
    ll md = *it;
    it = upper_bound(all(A), md + 2 * x);
    if(it == A.end()) return true;
    ll rg = *it;
    it = upper_bound(all(A), rg + 2 * x);
    if(it == A.end()) return true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    sort(all(A));
    ll lef = -1, rig = 1e14;
    while(rig - lef > 1){
        int mid = (lef + rig) / 2;
        if(f(mid, A)) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}

int main(){
    fast_io
    cin >> z ;
    rep(i,z) solve();
}