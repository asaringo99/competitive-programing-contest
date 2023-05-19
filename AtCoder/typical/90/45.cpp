#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define bit(a,b) a >> b & 1
#define dist(sx,sy,gx,gy) (sx - gx) * (sx - gx) + (sy - gy) * (sy - gy)

int n , k ;

ll X[20] , Y[20] ;
ll dp[1 << 16][16] ;
bool frag[1 << 16][16] ;

ll rec(int S , int v){
    if(frag[S][v] || v == 1) return dp[S][v] ;
    frag[S][v] = true ;
    ll res = LLONG_MAX ;
    for(int T = S ; T >= 0 ; T--){
        T &= S;
        if(T == S || T == 0) continue ;
        
    }
    return dp[S][v] = res ;
}

int main(){
    memset(dp,0,sizeof(dp)) ;
    cin >> n >> k ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(S,1 << n) {
        ll val = 0 ;
        rep(i,n) rrep(j,i+1,n) if(bit(S,i) && bit(S,j)) val = max(val,dist(X[i],Y[i],X[j],Y[j])) ;
        dp[S][1] = val ;
    }
    cout << rec((1 << n) - 1 , k) << endl ;
}