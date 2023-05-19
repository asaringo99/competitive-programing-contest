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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> A(n), B(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    int d = A[0] - B[0];
    int lef = w - h, rig = w - h;
    rrep(i,1,n){
        int a = A[i];
        int b = B[i] + d;
        int mag;
        if(b + h > a + w){
            int dist = (a + w) - (b + h);
            mag -= dist;
        }
    }
    cout << "YES" << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}