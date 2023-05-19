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

const int mod = 1000000007 ;

int z ;

void solve(){
    int n;
    string S;
    cin >> n >> S;
    vector<vector<ll>> dp(n+1,vector<ll>(4,0));
    dp[0][0] = 1;
    rep(i,n){
        if(S[i] == '?'){
            (dp[i+1][0] += 3 * dp[i][0]) %= mod;
            (dp[i+1][1] += dp[i][0] + 3 * dp[i][1]) %= mod;
            (dp[i+1][2] += dp[i][1] + 3 * dp[i][2]) %= mod;
            (dp[i+1][3] += dp[i][2] + 3 * dp[i][3]) %= mod;
            continue;
        }
        rep(j,4) (dp[i+1][j] += dp[i][j]) %= mod;
        if(S[i] == 'a') (dp[i+1][1] += dp[i][0]) %= mod;
        if(S[i] == 'b') (dp[i+1][2] += dp[i][1]) %= mod;
        if(S[i] == 'c') (dp[i+1][3] += dp[i][2]) %= mod;
    }
    cout << dp[n][3] << endl;
}

int main(){
    fast_input_output
    solve();
}