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
    int n, a, d;
    cin >> n >> a >> d;
    vector<int> T(n), V(n);
    vector<ld> res(n);
    rep(i,n) cin >> T[i] >> V[i];
    ld b = 0;
    rep(i,n){
        ld v = V[i];
        ld atim = (ld)v / a;
        ld dist = atim * v / 2;
        ld ans;
        if(dist > d){
            ans = sqrt((ld)d * 2 / a);
        }
        else{
            ans = atim + ((ld)d - dist) / v;
        }
        ans += T[i];
        if(ans < b){
            ans = b;
        }
        b = ans;
        res[i] = ans;
    }
    rep(i,n) cout << fixed << setprecision(25) << res[i] << endl;
}

int main(){
    fast_io
    solve();
}