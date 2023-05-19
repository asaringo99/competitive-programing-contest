#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
int A[3005] ;
ll dp[3005][3005] ;
bool ok ;

ll rec(int l , int r , bool k){
    if(l + 1 == r) return dp[l][r] = k ? -A[l] : A[l] ;
    if(dp[l][r] != -LLONG_MAX) return dp[l][r] ;
    if(!k) return dp[l][r] = max(A[l] + rec(l+1,r,(k+1)%2) , A[r-1] + rec(l,r-1,(k+1)%2)) ;
    else  return dp[l][r] = min(-A[l] + rec(l+1,r,(k+1)%2) , -A[r-1] + rec(l,r-1,(k+1)%2)) ;
}

int main(){
    rep(i,3005) fill(dp[i],dp[i]+3005,-LLONG_MAX) ;
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    cout << rec(0,n,0) << endl ;
}