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
    int k = n * m;
    vector<ll> A(k);
    rep(i,k) cin >> A[i];
    sort(all(A));
    if(n > m) swap(n,m);
    ll x = (A[k-1] - A[0]) * (m - 1) + (A[k-1] - A[1]) * (n - 1) + (A[k-1] - A[0]) * (n - 1) * (m - 1);
    ll y = (A[k-1] - A[0]) * (m - 1) + (A[k-2] - A[0]) * (n - 1) + (A[k-1] - A[0]) * (n - 1) * (m - 1);
    cout << max(x,y) << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}