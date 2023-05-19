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
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    vector<bool> B(d+1,false);
    for(int i = k; i <= d; i += k) B[i] = true;
    for(int i = l; i <= d; i += l) B[i] = true;
    for(int i = m; i <= d; i += m) B[i] = true;
    for(int i = n; i <= d; i += n) B[i] = true;
    int sum = 0;
    rep(i,d+1) if(B[i]) sum++;
    cout << sum << endl;
}

int main(){
    fast_io
    solve();
}