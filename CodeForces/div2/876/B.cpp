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
    int n;
    cin >> n;
    vector<pair<ll,ll>> A(n);
    vector<int> B(n+1);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        A[i] = {a,-b};
    }
    ll sum = 0;
    int cnt = 0;
    int broken = -1;
    sort(all(A));
    rep(i,n){
        auto[a,b] = A[i];
        if(a == cnt) broken = a;
        if(a == broken) continue;
        int tmp = cnt;
        cnt -= B[tmp];
        B[tmp] = 0;
        b = -b;
        sum += b;
        cnt++;
        B[a]++;
    }
    cout << sum << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}