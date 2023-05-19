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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"


ll dp[40][40][60];

ll rec(int h, int w, int k){
    if(h * w < k) return dp[h][w][k] = 1e18;
    if(dp[h][w][k] != 1e18) return dp[h][w][k];
    if(h * w == k) return dp[h][w][k] = 0;
    if(k == 0) return dp[h][w][k] = 0;
    if(h == 1 && w == 1) return dp[h][w][k] = 0;
    ll res = 1e18;
    rrep(i,1,h){
        rep(x,min(i*w,k)+1){
            chmin(res, rec(i,w,x) + rec(h-i,w,k-x) + w * w);
        }
    }
    rrep(i,1,w){
        rep(x,min(i*h,k)+1){
            chmin(res, rec(h,i,x) + rec(h,w-i,k-x) + h * h);
        }
    }
    return dp[h][w][k] = res;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << rec(a,b,c) << endl;
}

int main(){
    fast_io
    rep(i,40) rep(j,40) rep(x,60) dp[i][j][x] = 1e18;
    int t;
    cin >> t;
    rep(i,t) solve();
}