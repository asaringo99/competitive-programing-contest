#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
int n , a , b , c , d ;

ll dp[1010][1010] ;
ll comb[1010][1010] ;

void pascal(){
    comb[0][0] = 1 ;
    rep(i,1001){
        rep(j,1001){
            (comb[i+1][j] += comb[i][j]) %= mod ;
            (comb[i+1][j+1] += comb[i][j]) %= mod ;
        }
    }
}

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    pascal() ;
    cin >> n >> a >> b >> c >> d ;
    memset(dp,0,sizeof(dp)) ;
    dp[a-1][0] = 1 ;
    rep(i,n+1){
        rep(j,n+1){
            (dp[i+1][j] += dp[i][j]) %= mod ;
            if(i < a - 1 || i > b - 1) continue ;
            ll val = 1 ;
            rrep(k,1,n+1){
                if(j + (i + 1) * k > n) break ;
                (val *= comb[n-j-(i+1)*(k-1)][i+1]) %= mod ;
                (val *= powmod(k,mod-2)) %= mod ;
                if(k < c || k > d) continue ;
                (dp[i+1][j+(i+1)*k] += dp[i][j] * val % mod) %= mod ;
            }
        }
    }
    cout << dp[n][n] << endl ;
}