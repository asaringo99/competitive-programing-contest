#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
bool A[30][30] ;
ll dp[(1 << 21) + 10] ;

ll rec(int S , int v){
    if(v == n) dp[S] = 1 ;
    if(dp[S] >= 0) return dp[S] ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(!(S >> i & 1) && A[v][i]) (res += rec(S | (1 << i) , v + 1)) %= mod ;
    }
    return dp[S] = res ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    cout << rec(0,0) << endl ;
}