#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
bool dp[107][100007] ;
ll T[107] ;

int main(){
    cin >> n ;
    ll sum = 0 ;
    rep(i,n) {
        cin >> T[i] ;
        sum += T[i] ;
    }
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = true ;
    rep(i,n){
        rep(j,sum+1){
            if(dp[i][j]) {
                dp[i+1][j] = true ;
                dp[i+1][j+T[i]] = true ;
            }
        }
    }
    ll ans , val = INT_MAX ;
    rep(i,sum+1){
        if(dp[n][i]){
            if(val >= abs(sum/2 - i)){
                ans = i ;
                val = sum / 2 - i ;
            }
        }
    }
    cout << max(ans,sum-ans) << endl ;
}