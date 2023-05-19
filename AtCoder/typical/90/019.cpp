#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int A[405] ;
int dp[405][405] ;

int rec(int l , int r){
    if(r - l == 0) return dp[l][r] = 0 ;
    if(r - l == 2) return dp[l][r] = abs(A[l] - A[l+1]) ;
    if(dp[l][r] >= 0) return dp[l][r] ;
    int val = INT_MAX ;
    val = min(val,abs(A[l] - A[r-1]) + rec(l+1,r-1)) ;
    for(int i = l + 2 ; i <= r ; i += 2){
        val = min(val,abs(A[l] - A[i-1]) + rec(l+1,i-1) + rec(i,r)) ;
    }
    return dp[l][r] = val ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> n ;
    rep(i,2*n) cin >> A[i] ;
    cout << rec(0,2*n) << endl ;
}