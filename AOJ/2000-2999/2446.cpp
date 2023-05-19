#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , m ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return (ll)min(2e18l+1010,a/gcd(a,b)*1.0l*b) ;
}

ll dp[(1 << 20) + 10] , A[25] ;
double P[25] ;

void zeta(){
    rrep(S,1,1<<n) {
        ll lm = 1 ;
        rep(j,n) if(S >> j & 1) lm = lcm(lm,A[j]) ;
        dp[S] = m / lm ;
    }
}

void mebius(){
    rep(i,n) rep(S,1<<n) if(S >> i & 1){
        dp[S] -= dp[S ^ (1 << i)] ;
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> P[i] , P[i] /= 100 ;
    zeta() ; mebius() ;
    double ans = 0 ;
    rep(S,1<<n){
        double pre = 1 ;
        rep(i,n) pre *= (S >> i & 1 ? P[i] : (1 - P[i])) ;
        ans += pre * abs(dp[S]) ;
    }
    // if(ans > 1e8) ans = (ll)ans ;
    // string S = to_string(ans) ;
    // for(int i = 0 ; i < 9 ; i++) cout << S[i] ;
    // cout << endl ; 
    cout << fixed << setprecision(15) << ans << endl ;
}