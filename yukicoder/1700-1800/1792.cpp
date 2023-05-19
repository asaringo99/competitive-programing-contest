#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[1010][6] ;
ll V[1 << 6] ;
ll dp[1 << 6][4] ;

inline ll rec(ll S , int cnt){
    if(cnt == 3) return dp[S][cnt] = V[S] ;
    if(dp[S][cnt] != -1) return dp[S][cnt] ;
    ll res = V[S] ;
    for(int T = S ; T > 0 ; T = (T - 1) & S){
        if(T == S || T == 0) continue ;
        ll v = V[S^T] ;
        chmax(res,v*rec(T,cnt+1)) ;
    }
    // cout << res << endl;
    return dp[S][cnt] = res ;
}

int main(){
    cin >> n ;
    rep(i,n){
        rep(j,6) cin >> A[i][j] ;
    }
    rep(i,n) rep(S,1<<6){
        ll val = 1 ;
        rep(j,6) if(S >> j & 1) val *= A[i][j] ;
        chmax(V[S],val) ;
    }
    rep(S,1<<6) rep(i,4) dp[S][i] = -1 ;
    cout << rec((1<<6)-1,0) << endl ;
}