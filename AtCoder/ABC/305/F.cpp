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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int d[202];

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i,n+1) d[i] = -1;
    set<int> st;
    int cnt = 0;
    int now = 1;
    while(cnt <= 2 * n){
        if(cnt == 2 * n){
            cout << -1 << endl;
            return;
        }
        if(now == n){
            cout << "OK" << endl;
            return;
        }
        d[now] = cnt;
        int k;
        cin >> k;
        vector<int> G(k);
        rep(i,k) cin >> G[i];
        int dist = 1e9;
        int nextv = -1;
        for(int u : G){
            if(dist > d[u]){
                dist = d[u];
                nextv = u;
            }
        }
        cout << nextv << endl;
        now = nextv;
        cnt++;
    }
}

int main(){
    // fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}