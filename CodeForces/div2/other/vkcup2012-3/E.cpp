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
    vector<int> A(n);
    vector<ll> X(1000001,1e14);
    rep(i,n) cin >> A[i];
    rep(i,m) {
        int b;
        cin >> b;
        X[b] = i;
    }
    if(n == 1){
        if(X[A[0]] != 1e14) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    int lef = 0, rig = 0;
    ll xv = X[A[0]], yv = X[A[0]];
    int res = 0;
    while(lef < n){
        while(lef < n && X[A[lef]] == 1e14) {
            lef++;
            if(lef == n) break;
            rig = lef;
            xv = X[A[lef]];
            yv = X[A[lef]];
        }
        if(lef >= n) break;
        while(lef < n && rig < 2 * n){
            ll nv = X[A[rig%n]];
            if(nv < yv){
                ll k = (yv - nv) / m + 1;
                nv = nv + m * k;
            }
            if(nv == 1e14) break;
            if(nv - xv >= m) break;
            yv = nv;
            rig++;
            // cout << "u : " << lef << " " << rig << " " << xv << " " << yv << endl;
            chmax(res,rig-lef);
        }
        while(lef < n){
            lef++;
            if(lef == n) break;
            ll nv = X[A[lef]];
            if(nv < xv){
                ll k = (xv - nv) / m + 1;
                nv = nv + m * k;
            }
            xv = nv;
            // cout << "d : " << lef << " " << rig << " " << xv << " " << yv << endl;
            if(yv - xv < m) break;
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}