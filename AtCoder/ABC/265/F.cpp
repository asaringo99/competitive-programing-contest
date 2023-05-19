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

const int mod = 998244353 ;

int n, d ;
ll dp[101][1010][1010];
int A[2020], B[2020];

int main(){
    fast_input_output
    cin >> n >> d ;
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    dp[0][0][0] = 1;
    rep(i,n){
        int a = A[i], b = B[i];
        rep(j,d+1) rep(k,d+1){
            if(d-j > d-k){
                int r = d-k;
                rrep(x,b-r,b+r+1){
                    if(j + abs(a - x) > d) continue;
                    (dp[i+1][j+abs(a-x)][k+abs(b-x)] += dp[i][j][k]) %= mod;
                }
            }
            else{
                int r = d-j;
                rrep(x,a-r,a+r+1){
                    if(k + abs(b - x) > d) continue;
                    (dp[i+1][j+abs(a-x)][k+abs(b-x)] += dp[i][j][k]) %= mod;
                }
            }
        }
    }
    ll res = 0 ;
    rep(i,d+1) rep(j,d+1) (res += dp[n][i][j]) %= mod;
    cout << res << endl;
}