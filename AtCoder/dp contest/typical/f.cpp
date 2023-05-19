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

int n , k ;
ll dp[1010101] , S[1010101] ;

int main(){
    cin >> n >> k ;
    dp[0] = 1 ;
    S[0] = 1 ; S[1] = 1 ;
    rrep(i,2,n+1){
        dp[i] = (S[i-1] - (i-k-1 < 0 ? 0 : S[i-k-1]) + mod) % mod ;
        S[i] = (S[i-1] + dp[i] + mod) % mod ;
    }
    cout << (S[n-1] - S[n-k] + mod) % mod << endl ;
}