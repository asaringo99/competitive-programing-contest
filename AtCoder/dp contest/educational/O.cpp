#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
bool A[25][25] ;
ll dp[(1 << 21) + 7][22] ;

int rec(int S , int v){
    if(S == (1 << n) - 1) return dp[S][v] = 1 ;
    if(dp[S][v] >= 0) return dp[S][v] ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        if((S >> i) & 1) continue ;
        if(!A[i][v]) continue ;
        res += rec(S | (1 << i) , v + 1) ;
        res %= mod ;
    }
    return dp[S][v] = res ;
}

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    memset(dp,-1,sizeof(dp)) ;
    cout << rec(0,0) << endl ;
}