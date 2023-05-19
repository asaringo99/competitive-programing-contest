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

int H, W;
ll R[2020], C[2020];
char A[2020][2020];
ll dp[2020][2020][2][2];
ll ep[2020][2020][2][2];

int main(){
    fast_io
    cin >> H >> W;
    rep(i,H) cin >> R[i];
    rep(i,W) cin >> C[i];
    rep(i,H) rep(j,W) cin >> A[i][j];
    rep(i,H+1) rep(j,W+1) rep(x,2) rep(y,2) dp[i][j][x][y] = 1e18;
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = R[0];
    dp[0][0][1][0] = C[0];
    dp[0][0][1][1] = R[0]+C[0];
    rep(i,H) rep(j,W){
        int a = A[i][j]-'0';
        rep(r,2) rep(c,2){
            if((r+c+a)%2==0) continue;
            // ->
            if(j<W-1){
                int nv = A[i][j+1]-'0';
                ll cost = (nv+c)%2==0 ? C[j+1] : 0;
                chmin(dp[i][j+1][1-(nv+c)%2][c], dp[i][j][r][c]+cost);
            }
            if(i<H-1){
                int nv = A[i+1][j]-'0';
                ll cost = (nv+r)%2==0 ? R[i+1] : 0;
                chmin(dp[i+1][j][r][1-(nv+r)%2], dp[i][j][r][c]+cost);
            }
        }
    }
    rep(i,H+1) rep(j,W+1) rep(x,2) rep(y,2) ep[i][j][x][y] = 1e18;
    ep[0][0][0][0] = 0;
    ep[0][0][0][1] = R[0];
    ep[0][0][1][0] = C[0];
    ep[0][0][1][1] = R[0]+C[0];
    rep(i,H) rep(j,W){
        int a = A[i][j]-'0';
        rep(r,2) rep(c,2){
            if((r+c+a)%2==1) continue;
            // ->
            if(j<W-1){
                int nv = A[i][j+1]-'0';
                ll cost = (nv+c)%2==1 ? C[j+1] : 0;
                chmin(ep[i][j+1][(nv+c)%2][c], ep[i][j][r][c]+cost);
            }
            if(i<H-1){
                int nv = A[i+1][j]-'0';
                ll cost = (nv+r)%2==1 ? R[i+1] : 0;
                chmin(ep[i+1][j][r][(nv+r)%2], ep[i][j][r][c]+cost);
            }
        }
    }
    ll res = 1e18;
    rep(i,2) rep(j,2) chmin(res,dp[H-1][W-1][i][j]);
    rep(i,2) rep(j,2) chmin(res,ep[H-1][W-1][i][j]);
    cout << res << endl;
}