#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int k ;
ll dp[100007] , S[100007] ;

int main(){
    cin >> k ;
    if(k % 9 != 0){
        cout << 0 << endl ;
        return 0 ;
    }
    memset(dp,0,sizeof(dp)) ;
    dp[0] = 1 ;
    S[0] = 0 ;
    for(int i = 1 ; i <= k ; i++){
        S[i] = (S[i-1] + dp[i-1]) % mod ;
        if(i > 9) dp[i] += (S[i] - S[i-9] + mod) ;
        else dp[i] += S[i] ;
        dp[i] %= mod ;
    }
    cout << dp[k] << endl ;
}