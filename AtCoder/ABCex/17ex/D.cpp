#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n , m ;
int f[101010] , t[101010] ;
ll S[101010] , dp[101010] ;

int main(){
    cin >> n >> m ;
    rrep(i,1,n+1) cin >> f[i] ;
    dp[0] = 1 ;
    S[0] = 1 ;
    rep(i,m+1) t[i] = -1 ;
    int c = -1 ;
    rrep(i,1,n+1){
        if(t[f[i]] != -1){
            c = max(c,t[f[i]]) ;
            t[f[i]] = i ;
        }
        if(c == -1) (dp[i] += S[i-1]) %= mod ;
        if(c != -1) (dp[i] += S[i-1] - S[c-1] + mod) %= mod ;
        S[i] = (S[i-1] + dp[i]) % mod ;
        t[f[i]] = i ;
    }
    cout << dp[n] << endl ;
}