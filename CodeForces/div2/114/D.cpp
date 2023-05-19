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

ld dp[202][202][222]; // i: 何個目, j: 勝利数, x: 空き容量

void solve(){
    int n, l, k;
    cin >> n >> l >> k;
    vector<pair<int,int>> X(n);
    rep(i,n) cin >> X[i].second;
    rep(i,n) cin >> X[i].first;
    sort(all(X), greater<pair<int,int>>());
    vector<int> A(n), B(n);
    rep(i,n) {
        A[i] = X[i].second;
        B[i] = X[i].first;
    }
    chmin(k,n);
    dp[0][0][k] = (ld)1;
    rep(i,n){
        ld p = A[i];
        ld q = (ld)100 - p;
        int c = B[i];
        bool ok = c == -1 ? true : false;
        rep(j,i+1){
            if(ok){
                rep(x,n+10){
                    if(x > 0) dp[i+1][j+1][x-1] += dp[i][j][x] * p / (ld)100;
                    dp[i+1][j][x] += dp[i][j][x] * q / (ld)100;
                }
            }
            else{
                rep(x,n+10){
                    int y = x + c >= n+9 ? n+9 : x + c;
                    dp[i+1][j+1][y] += dp[i][j][x] * p / (ld)100;
                    dp[i+1][j][x] += dp[i][j][x] * q / (ld)100;
                }
            }
        }
    }
    ld res = 0;
    rrep(i,l,n+1) rep(j,n+10) res += dp[n][i][j];
    cout << fixed << setprecision(15) << res << endl;
}

int main(){
    fast_io
    solve();
}