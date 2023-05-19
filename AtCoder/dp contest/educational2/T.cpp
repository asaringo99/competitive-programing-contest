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

const int mod = 1000000007 ;

int n ;
string s ;
ll dp[3030][3030] , S[3030] ;

int main(){
    cin >> n >> s ;
    rep(i,n) dp[0][i] = 1 ;
    rrep(i,1,n){
        memset(S,0,sizeof(S)) ;
        rep(j,n+1-i) S[j] = j == 0 ? dp[i-1][j] : (S[j-1] + dp[i-1][j]) % mod ;
        rep(j,n-i){
            if(s[i-1] == '>') dp[i][j] = (S[n-i] - S[j] + mod) % mod ;
            if(s[i-1] == '<') dp[i][j] = (S[j] + mod) % mod ;
        }
    }
    cout << dp[n-1][0] << endl ;
}