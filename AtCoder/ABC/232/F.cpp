#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , x , y ;
ll A[20] , B[20] ;
ll dp[1 << 20] ;

int main(){
    cin >> n >> x >> y ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(S,1<<n) dp[S] = 1e18 ;
    dp[0] = 0 ;
    rep(S,1<<n){
        ll count = 0 ;
        ll popcount = bit_count(S) ;
        rep(i,n){
            if(S >> i & 1) continue ;
            chmin(dp[S | 1 << i],dp[S] + count * y + x * abs(A[i] - B[popcount])) ;
            count++ ;
        }
    }
    cout << dp[(1 << n) - 1] << endl ;
}