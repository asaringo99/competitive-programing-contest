#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 300007 ;

int dp1[MAX_N] , dp2[MAX_N] , A[MAX_N] , X[MAX_N] , Y[MAX_N] ;
int n ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    fill(dp1,dp1+MAX_N,INT_MAX) ;
    fill(dp2,dp2+MAX_N,INT_MAX) ;

    rep(i,n){
        int a = A[i] , b = A[n-1-i] ;
        auto it1 = lower_bound(dp1,dp1+MAX_N,a) ;
        auto it2 = lower_bound(dp2,dp2+MAX_N,b) ;
        int x = it1 - dp1 , y = it2 - dp2 ;
        dp1[x] = a ;
        dp2[y] = b ;
        X[i] = x ;
        Y[i] = y ;
    }
    int res = 0 ;
    rep(i,n){
        res = max(res,X[i]+Y[n-1-i]+1) ;
    }
    cout << res << endl ;
}