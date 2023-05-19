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

const int mod = 1234567 ;

int n ;
ll p ;
ll H[505050] , S[505050] , T[505050] ;
ll dp[505050] ;

int main(){
    cin >> n >> p ;
    rep(i,n) cin >> H[i] , S[i+1] = S[i] + H[i] ;

    dp[0] = 1 ;
    T[0] = 1 ;
    rrep(i,1,n+1){
        if(S[i] - p <= 0) dp[i] = T[i-1] ;
        else{
            auto it = lower_bound(S,S+n+1,S[i]-p) ; it-- ;
            int j = it - S ;
            dp[i] = (T[i-1] - T[j] + mod) % mod ;
        }
        T[i] = (T[i-1] + dp[i]) % mod ;
    }
    cout << dp[n] << endl ;
}