#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[440] , dp[440][440] , S[440] ;

ll rec(ll lef , ll rig){
    if(rig - lef == 1) return dp[lef][rig] = 0 ;
    if(dp[lef][rig] >= 0) return dp[lef][rig] ;
    ll res = LLONG_MAX , val = LLONG_MAX ;
    for(int i = lef + 1 ; i < rig ; i++){
        res = min(res,rec(lef,i)+rec(i,rig)+S[rig]-S[lef]) ;
    }
    return dp[lef][rig] = res ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) S[i+1] = S[i] + A[i] ;
    cout << rec(0,n) << endl ;
}