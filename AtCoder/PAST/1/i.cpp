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

int n, m;
ll dp[1010][1<<11];

int main(){
    fast_io
    cin >> n >> m;
    vector<pair<ll,int>> vec(m);
    rep(i,m){
        string s;
        ll c;
        cin >> s >> c;
        int v = 0;
        rep(j,n){
            if(s[j] == 'Y') v += 1 << j;
        }
        vec[i] = {c, v};
    }
    rep(i,m+1) rep(S,1<<n) dp[i][S] = 1e18;
    dp[0][0] = 0;
    rep(i,m){
        auto [c,v] = vec[i];
        rep(S,1<<n){
            chmin(dp[i+1][S], dp[i][S]);
            chmin(dp[i+1][S | v], dp[i][S] + c);
        }
    }
    if(dp[m][(1<<n)-1] == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[m][(1<<n)-1] << endl;
}