#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
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
    int k;
    string S;
    cin >> S;
    int n = S.size();
    cin >> k;
    vector<pair<char,char>> P(k);
    rep(i,k){
        string s;
        cin >> s;
        P[i] = {s[0],s[1]};
    }
    vector<vector<int>> dp(n+1,vector<int>(2,1e8));
    dp[0][0] = 0;
    dp[0][1] = 1;
    rrep(i,1,n){
        char a = S[i];
        char b = S[i-1];
        bool ok = false;
        for(auto[x,y] : P){
            if(x == a && y == b) ok = true;
            if(x == b && y == a) ok = true;
        }
        if(ok){
            // chmin(dp[i][1], dp[i-1][1] + 1);
            chmin(dp[i][1], dp[i-1][0] + 1);
            chmin(dp[i][0], dp[i-1][1]);
        }
        else{
            // chmin(dp[i][1], dp[i-1][1] + 1);
            chmin(dp[i][1], dp[i-1][0] + 1);
            chmin(dp[i][0], dp[i-1][0]);
            chmin(dp[i][0], dp[i-1][1]);
        }
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main(){
    fast_io
    solve();
}