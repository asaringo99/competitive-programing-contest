#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[3030] , dp[3030][3030] ;

ll rec(int lef , int rig){
    if(lef == rig) return dp[lef][rig] = A[lef] ;
    if(dp[lef][rig] >= 0) return dp[lef][rig] ;
    ll res = max(A[lef] - rec(lef+1,rig) , A[rig] - rec(lef,rig-1)) ;
    return dp[lef][rig] = res ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    memset(dp,-1,sizeof(dp)) ;
    ll res = rec(0,n-1) ;
    cout << res << endl ;
}