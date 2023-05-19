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
    int n, k;
    cin >> n >> k;
    rep(i,n+1){
        int j = n - i;
        int v = i * (i - 1) / 2;
        int u = j * (j - 1) / 2;
        if(v + u == k){
            cout << "YES" << endl ;
            rep(x,i) cout << 1 << " ";
            rep(x,j) cout << -1 << " ";
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl ;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}