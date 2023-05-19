#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
ll dp[2020][2020] , ep[2020][2020] , S[2020] ;
ll A[2020] ;
bool B[2020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        cin >> A[i] ;
        if(!B[A[i]]) dp[i][0] = 1 ;
        B[A[i]] = true ;
    }
    rep(i,n){
        rrep(j,1,i+1){
            dp[i][j] += S[j-1] - ep[A[i]][j] ;
            dp[i][j] += mod ;
            dp[i][j] %= mod ;
        }
        rep(j,n+1) (ep[A[i]][j] += dp[i][j]) %= mod ;
        rep(j,n+1) (S[j] += dp[i][j]) %= mod ;
    }
    rep(i,n){
        ll res = 0 ;
        rep(j,n){
            (res += dp[j][i]) %= mod ;
        }
        cout << res << endl ;
    }
}