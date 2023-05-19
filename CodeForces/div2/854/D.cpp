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

int n, k;
vector<vector<ll>> dp;
vector<ll> A, C, H;

inline ll rec(int x, int y){
    if(x == n || y == n) return dp[x][y] = 0;
    if(dp[x][y] != -1) return dp[x][y];
    ll res = 1e18;
    if(x > y) swap(x,y);
    if(x == 0 && y == 0){
        res = rec(0,1) + C[A[1]];
    }
    else if(x == 0){
        if(A[y] == A[y+1]) chmin(res,rec(0,y+1)+H[A[y]]);
        chmin(res,rec(0,y+1)+C[A[y+1]]);
        chmin(res,rec(y+1,y)+C[A[y+1]]);
    }
    else{
        if(A[y] == A[y+1]) chmin(res,rec(x,y+1)+H[A[y+1]]);
        if(A[x] == A[y+1]) chmin(res,rec(y+1,y)+H[A[y+1]]);
        chmin(res,rec(x,y+1)+C[A[y+1]]);
        chmin(res,rec(y+1,y)+C[A[y+1]]);
    }
    dp[x][y] = res;
    dp[y][x] = res;
    return res;
}

void solve(){
    cin >> n >> k;
    A.clear();
    C.clear();
    H.clear();
    A.resize(n+1);
    C.resize(k);
    H.resize(k);
    // vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(k+1,1e17)));
    dp = vector<vector<ll>>(n+2, vector<ll>(n+2,-1));
    rrep(i,1,n+1) cin >> A[i], A[i]--;
    rep(i,k) cin >> C[i];
    rep(i,k) cin >> H[i];
    cout << rec(0,0) << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}