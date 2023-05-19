#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
int n , L ;

ll dp[300007] ;

int main(){
    cin >> n >> L ;
    memset(dp,0,sizeof(dp)) ;
    dp[0] = 1 ;
    rep(i,300000 - L){
        (dp[i+1] += dp[i]) %= mod ;
        (dp[i+L] += dp[i]) %= mod ;
    }
    cout << dp[n] << endl ;
}