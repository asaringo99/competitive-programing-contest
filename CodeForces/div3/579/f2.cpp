#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n, r;
P X[101];
priority_queue<P> pls, mns;
vector<P> pl;
vector<TP> mn;

int dp[101][60606];

void solve(){
    cin >> n >> r;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(b >= 0) pl.push_back({a,b});
        else mn.push_back({a+b,a,-b});
    }
    sort(pl.begin(),pl.end());
    sort(mn.begin(),mn.end(),greater<TP>());
    int cnt = 0;
    rep(i,pl.size()){
        auto [a,b] = pl[i];
        if(r >= a) {
            r += b;
            cnt++;
        }
    }
    int m = mn.size();
    rep(i,m+1) rep(j,60606) dp[i][j] = -1e8;
    dp[0][r] = cnt;
    rep(i,m){
        auto [d,a,b] = mn[i];
        rep(j,60001){
            chmax(dp[i+1][j], dp[i][j]);
            if(j >= a && j - b >= 0) chmax(dp[i+1][j-b], dp[i][j] + 1);
        }
    }
    int res = 0;
    rep(i,60001) chmax(res,dp[m][i]);
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}