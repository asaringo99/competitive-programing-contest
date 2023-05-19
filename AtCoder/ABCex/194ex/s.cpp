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

string S ;
int k ;
vector<int> digit ;
ll dp[202020][2][20] ; 


int main(){
    cin >> S >> k ;
    int n = S.size() ;
    rep(i,n){
        if(S[i] - '0' > 9) digit.push_back(S[i] - '0' - 7) ;
        else digit.push_back(S[i] - '0') ;
    }
    set<int> st ;
    int kind = 0 ;
    dp[0][0][0] = 1 ;
    rep(i,n){
        // Leading 0
        {
            if(i > 0) (dp[i+1][1][1] += 15) %= mod ;
        }
        // 0
        {
            int now = kind ;
            kind |= 1 << digit[i] ;
            dp[i+1][0][bit_count(kind)] = dp[i][0][bit_count(now)] ;
            int fir = 0 ;
            if(i == 0) fir = 1 ;
            rrep(x,fir,digit[i]){
                int moc = now ;
                moc |= 1 << x ;
                (dp[i+1][1][bit_count(moc)] += dp[i][0][bit_count(now)]) %= mod ;
            }
        }
        // 1
        {
            rrep(j,1,17){
                (dp[i+1][1][j] += dp[i][1][j] * j) %= mod ;
                if(j+1<=k) (dp[i+1][1][j+1] += dp[i][1][j] * (16 - j) % mod) %= mod ;
            }
        }
    }
    ll res = (dp[n][0][k] + dp[n][1][k]) % mod ;
    cout << res << endl ;
}