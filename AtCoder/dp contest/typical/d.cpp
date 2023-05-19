#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll d ;

void f(ll& d , ll x , ll& y){
    while(d % x == 0){
        d /= x ;
        y++ ;
    }
}

ld dp[222][111][111] ;

int main(){
    cin >> n >> d ;
    ll a = 0 , b = 0 , c = 0 ;
    f(d,2,a) ;
    f(d,3,b) ;
    f(d,5,c) ;
    if(d != 1){
        cout << 0 << endl ;
        return 0 ;
    }
    dp[0][0][0] = 1 ;
    rep(i,n) for(int x=2*n;x>=0;x--) for(int y=n;y>=0;y--) for(int z=n;z>=0;z--){
        // 1
        dp[x][y][z] /= 6 ;
        // 4
        dp[x+2][y][z] += dp[x][y][z] ;
        // 2
        dp[x+1][y][z] += dp[x][y][z] ;
        // 3
        dp[x][y+1][z] += dp[x][y][z] ;
        // 5
        dp[x][y][z+1] += dp[x][y][z] ;
        // 6
        dp[x+1][y+1][z] += dp[x][y][z] ;
    }
    ld res = 0 ;
    rep(x,2*n+1) rep(y,n+1) rep(z,n+1){
        if(x >= a && y >= b && z >= c) res += dp[x][y][z] ;
    }
    cout << fixed << setprecision(25) << res << endl ;
}