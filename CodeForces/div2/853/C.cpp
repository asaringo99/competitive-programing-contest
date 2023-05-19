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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<vector<int>> in(n+m), out(n+m);
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n){
        in[A[i]].push_back(0);
    }
    rrep(i,1,m+1){
        int v, x;
        cin >> v >> x;
        v--; x--;
        if(A[v] == x) continue;
        out[A[v]].push_back(i);
        A[v] = x;
        in[x].push_back(i);
    }
    rep(i,n){
        out[A[i]].push_back(m+1);
    }
    ll res = 0;
    rep(i,n+m){
        ll insum = 0;
        rep(j,in[i].size()){
            insum += out[i][j] - in[i][j];
        }
        // cout << i << " : " << insum << " " << insum * (m + 1 - insum) << endl;
        res += insum * (m - insum + 1) + insum * (insum - 1) / 2;
    }
    cout << res << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}