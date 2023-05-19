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

int n;
string S;

ll dp[3030][3030];
ll C[3030], D[3030];

int main(){
    fast_io
    cin >> n >> S;
    rep(i,n) cin >> C[i];
    rep(i,n) cin >> D[i];
    rep(i,n+1) rep(j,n+1) dp[i][j] = 1e18;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,i+1){
            if(S[i] == '(') {
                chmin(dp[i+1][j+1], dp[i][j]);
                if(j > 0) chmin(dp[i+1][j-1], dp[i][j] + C[i]);
                chmin(dp[i+1][j], dp[i][j] + D[i]);
            }
            if(S[i] == ')') {
                chmin(dp[i+1][j+1], dp[i][j] + C[i]);
                if(j > 0) chmin(dp[i+1][j-1], dp[i][j]);
                chmin(dp[i+1][j], dp[i][j] + D[i]);
            }
        }
    }
    cout << dp[n][0] << endl;
}