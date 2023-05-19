#include <bits/stdc++.h>
using namespace std ;
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

const int mod = 100000 ;

int n , m , s ;
int dp[2020][3030] ;
int S[2020][3030] ;

int main(){
    cin >> n >> m >> s ;
    n = n * n ;
    dp[0][0] = 1 ;
    rrep(i,1,n+1){
        rep(j,s+1){
            rep(k,m){
                S[k+1][j] = S[k][j] + dp[k][j] ;
                S[k+1][j] %= mod ;
            }
        }
        rep(j,s+1){
            rep(k,m+1){
                if(j-k<0) break ; 
                dp[k][j] = S[k][j-k] ;
            }
        }
    }
    ll res = 0 ;
    rep(i,m+1) (res += dp[i][s]) %= mod ;
    cout << res << endl ;
}