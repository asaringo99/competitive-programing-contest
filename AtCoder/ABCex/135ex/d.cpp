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

const int mod = 1000000007 ;
int n ;
string S ;

ll dp[101010][20] ;

int main(){
    fast_input_output
    cin >> S ;
    n = S.size() ;
    dp[0][0] = 1 ;
    rep(i,n) rep(j,13){
        if(S[i] == '?'){
            rep(k,10){
                int v = j * 10 + k ;
                (dp[i+1][v%13] += dp[i][j]) %= mod ;
            }
        }
        else{
            int a = S[i] - '0' ;
            int v = j * 10 + a ;
            (dp[i+1][v%13] += dp[i][j]) %= mod ;
        }
    }
    cout << dp[n][5] << endl ;
}