#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define BIT(i,j) (i >> j) & 1

int n ;
ll dp[(1 << 20)] , V[(1 << 20)] , A[20][20] ;

int popcount(int S){
    int count = 0 ;
    for(int i = 0 ; i < n ; i++) if(S >> i & 1) count++ ;
    return count ;
}

ll rec(int S){
    if(dp[S] != -1) return dp[S] ;
    // if(popcount(S) == 1) return dp[S] = 0 ;
    ll val = V[S] ;
    for(int T = S ; T > 0 ; T = (T - 1) & S){
        if(T == S || T == 0) continue ;
        val = max(val,rec(T)+rec(T^S)) ;
    }
    return dp[S] = val ;
}

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    rep(S,1<<n) rep(i,n) rrep(j,i+1,n) if(BIT(S,i) && BIT(S,j)) V[S] += A[i][j] ;
    memset(dp,-1,sizeof(dp)) ;
    cout << rec((1<<n)-1) << endl ;
}