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

ld dp[1010][1010][2];

ld rec(int w, int b, int t){
    if(dp[w][b][t] != -1) return dp[w][b][t];
    if(t == 1){
        if(w == 0) return dp[w][b][t] = 1;
        if(b == 0) return dp[w][b][t] = 1;
        ld p;
        if(b == 1) p = 1 - rec(w-1,0,0);
        else p = (ld)w / (w + b - 1) * (1 - rec(w-1,b-1,0)) + (ld)(b - 1) / (w + b - 1) * (1 - rec(w,b-2,0));
        dp[w][b][t] = (ld)w / (w + b) + (ld)b / (w + b) * p;
        return dp[w][b][t];
    }
    else{
        if(w == 0) return dp[w][b][t] = 0;
        if(b == 0) return dp[w][b][t] = 1;
        dp[w][b][t] = (ld)w / (w + b) + (ld)b / (w + b) * (1 - rec(w,b-1,1));
        return dp[w][b][t];
    }
}

void solve(){
    int w, b;
    cin >> w >> b;
    rep(i,w+1) rep(j,b+1) rep(k,2) dp[i][j][k] = -1;
    cout << fixed << setprecision(25) << rec(w,b,0) << endl;
}

int main(){
    fast_io
    solve();
}