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

int n, m, k;

void solve(){
    cin >> n >> m >> k;
    vector<vector<int>> A(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> A[i][j];
    bool flg = false;
    if(n < m){
        flg = true;
        swap(n,m);
        vector<vector<int>> Z(n,vector<int>(m));
        rep(i,n) rep(j,m) Z[i][j] = A[j][i];
        A = Z;
    }
    vector<set<int>> vec(n);
    map<pair<int,int>, bool> mp;
    rep(i,k){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(flg) swap(x,y);
        vec[x].insert(y);
        mp[{x,y}] = true;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(1<<m,1e18));
    rep(S,1<<m){
        ll res = 0;
        rep(i,m) if(S >> i & 1) res += A[0][i];
        bool ok = true;
        for(int u : vec[0]) if(!(S >> u & 1)) ok = false;
        if(ok) dp[0][S] = res;
    }
    rep(i,n){
        rep(S,1<<m){
            for(int u : vec[i]) if(!(S >> u) & 1) continue;
            for(int T = S; T > 0; T = (T - 1) & S){
                if(T == 0) break;
                ll res = 0;
                int U = T ^ S;
                rep(j,m) if(U >> j & 1) res += A[i][j];
                chmin(dp[i][S],dp[i][T]+res);
            }
            if(i == n - 1) continue;
            for(int T = S; T >= 0; T = (T - 1) & S){
                if(T == 0) continue;
                ll res = 0;
                rep(j,m) if(T >> j & 1) res += A[i+1][j];
                chmin(dp[i+1][T],dp[i][S]+res);
            }
        }
    }
}

int main(){
    fast_io
    solve();
}