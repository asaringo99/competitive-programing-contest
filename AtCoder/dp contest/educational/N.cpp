#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
ll A[405] , dp[405][405] ;

ll rec(int l , int r){
    if(dp[l][r] != -1) return dp[l][r] ;
    if(r - l == 2) return dp[l][r] = A[l] + A[l+1] ;
    if(r - l == 1) return dp[l][r] = A[l] ;
    ll val = LLONG_MAX ;
    for(int i = l + 1 ; i < r ; i++){
        ll tmp = rec(l,i) + rec(i,r) ;
        tmp *= 2 ;
        val = min(val,tmp) ;
    }
    return dp[l][r] = val ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    cout << rec(0,n) << endl ;
    cout << dp[0][3] << endl ;
}