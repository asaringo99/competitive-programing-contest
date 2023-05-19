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
ll x , y ;
ll A[20] , B[20] ;
ll dp[1<<20] ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(S,1<<n) dp[S] = 2e18 ;
    dp[0] = 0 ;
    rep(S,1<<n){
        int count = 0 , ord =bit_count(S) ;
        rep(i,n) {
            if(S >> i & 1) count++ ;
            else chmin(dp[S|1<<i],dp[S]+y*(ll)(i-count)+x*abs(A[i]-B[ord])) ;
        }
    }
    cout << dp[(1<<n)-1] << endl ;
}