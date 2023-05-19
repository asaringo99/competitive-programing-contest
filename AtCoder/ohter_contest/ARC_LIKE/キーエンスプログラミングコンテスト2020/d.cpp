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

int n;
int A[20], B[20];
int dp[1<<20][20];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(S,1<<n) rep(i,n) dp[S][i] = 1e9;
    rep(i,n){
        dp[1<<i][i] = i;
    }
    rep(S,1<<n){
        int bc = bit_count(S);
        rep(i,n){
            if(!(S >> i & 1)) continue;
            int x = abs(i - bc) % 2 == 0 ? B[i] : A[i];
            int cnt = 0;
            rep(j,n){
                if(S >> j & 1) {
                    cnt++;
                    continue;
                }
                int y = abs(j - bc) % 2 == 0 ? A[j] : B[j];
                if(x > y) continue;
                chmin(dp[S | (1 << j)][j], dp[S][i] + j - cnt);
            }
        }
    }
    int res = 1e9;
    rep(i,n) chmin(res,dp[(1<<n)-1][i]);
    res = res == 1e9 ? -1 : res;
    cout << res << endl;
}