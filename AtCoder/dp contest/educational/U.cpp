#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[20][20] ;
ll dp[(1 << 16) + 7] ;
bool used[(1 << 16) + 7] ;

ll rec(int S){
    if(used[S]) return dp[S] ;
    used[S] = true ;
    ll val = 0 ;
    rep(i,n) rrep(j,i+1,n) if((S >> i & 1) && (S >> j & 1)) val += A[i][j] ;
    for(int T = S ; T >= 0 ; T--){
        T &= S ;
        if(T == S || T == 0) continue ;
        val = max(val,rec(T)+rec(S^T)) ;
    }
    return dp[S] = val ;
}

int main(){
    cin >> n ;
    fill(dp,dp+(1<<16)+17,-100000000000000) ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    cout << rec((1 << n) - 1) << endl ;
}