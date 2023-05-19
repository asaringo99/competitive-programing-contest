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

int n ;
string S ;

int main(){
    fast_input_output
    cin >> n >> S ;
    int res = 0 ;
    rrep(i,1,n){
        int x = i , y = n - i ;
        string s = "" , t = "" ;
        rep(j,i) s += S[j] ;
        rrep(j,i,n) t += S[j] ;
        vector<vector<int>> dp(x+1,vector<int>(y+1,0)) ;
        rrep(i,1,x+1) rrep(j,1,y+1){
            if(s[i-1] == t[j-1]) chmax(dp[i][j],dp[i-1][j-1]+1) ;
            chmax(dp[i][j],dp[i-1][j]) ;
            chmax(dp[i][j],dp[i][j-1]) ;
        }
        chmax(res,dp[x][y]) ;
    }
    cout << n - 2 * res << endl ;
}