#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

const int mod = 998244353 ;

int n ;
P X[5050] ;
ll A[5050] , B[5050] ;
ll dp[5050][5050] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i].first ;
    rep(i,n) cin >> X[i].second;
    sort(X,X+n) ;
    rep(i,n) A[i] = X[i].first , B[i] = X[i].second ;
    ll res = 0 ;
    dp[0][0] = 1 ;
    rep(i,n){
        rep(j,5001){
            (dp[i+1][j] += dp[i][j]) %= mod ;
            if(j + B[i] <= 5000){
                (dp[i+1][j+B[i]] += dp[i][j]) %= mod ;
                if(j+B[i]<=A[i]) (res += dp[i][j]) %= mod ;
            }
        }
    }
    cout << res << endl ;
}