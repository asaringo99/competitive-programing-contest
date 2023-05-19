using namespace std ;
#include <bits/stdc++.h>
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<bool,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int dx[] = {1,0} , dy[] = {0,1} ;

int H , W , K ;
ll dp[33][33][66] ;
ll A[33][33] ;

ll f(ll v){
    rep(i,H) rep(j,W) rep(k,H+W) dp[i][j][k] = 1e18 ;
    if(v <= A[0][0]) dp[0][0][1] = A[0][0] ;
    else dp[0][0][0] = 0 ;
    rep(i,H) rep(j,W) rep(k,H+W) {
        if(i + 1 < H){
            if(v <= A[i+1][j]) chmin(dp[i+1][j][k+1],dp[i][j][k]+A[i+1][j]) ;
            else chmin(dp[i+1][j][k],dp[i][j][k]) ;
        }
        if(j + 1 < W){
            if(v <= A[i][j+1]) chmin(dp[i][j+1][k+1],dp[i][j][k]+A[i][j+1]) ;
            else chmin(dp[i][j+1][k],dp[i][j][k]) ;
        }
    }
    ll res = 1e13 , sum = 0 ;
    rrep(i,K,H+W){
        chmin(res,dp[H-1][W-1][i]-sum) ;
        sum += v ;
    }
    return res ;
}

int main(){
    fast_input_output
    cin >> H >> W >> K ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    ll lef = 0 , rig = 1e10 , count = 0 ;
    while(count < 200){
        ll lm = (2LL * lef + rig) / 3 , rm = (lef + 2LL * rig) / 3 ;
        if(f(lm) > f(rm)) lef = lm ;
        else rig = rm ;
        count++ ;
    }
    ll res = 1e18 ;
    rrep(i,lef,rig+1) chmin(res,f(i)) ;
    cout << res << endl ;
}