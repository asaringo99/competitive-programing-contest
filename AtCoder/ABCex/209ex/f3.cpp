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

int n ;
ll H[4040];
ll dp[4040][4040], S[4040];

int main(){
    cin >> n ;
    rep(i,n) cin >> H[i];
    dp[0][0] = 1;
    rrep(i,1,n){
        rep(j,n) S[j+1] = (S[j] + dp[i-1][j]) % mod;
        rep(j,i+1){
            if(H[i] >= H[i-1]) dp[i][j] += (S[n] - S[j] + mod) % mod;
            if(H[i] <= H[i-1]) dp[i][j] += S[j];
            dp[i][j] %= mod;
        }
    }
    ll res = 0;
    rep(i,n) (res += dp[n-1][i]) %= mod;
    cout << res << endl;
}