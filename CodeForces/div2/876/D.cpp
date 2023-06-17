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
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+10,vector<int>(2,1e9)));
    vector<int> res(n+1,1e9);
    dp[0][0][0] = 0;
    rep(i,n){
        rrep(j,i+1,n){
            
            rep(k,n){
                // 0

                // 1
            }
        }
    }
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}