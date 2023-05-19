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
string S , X ;
int dp[202020][7] ;

int rec(int k , int s){
    if(dp[k][s] != -1) return dp[k][s] ;
    int v = S[k] - '0' ;
    if(X[k] == 'A'){
        int aoki = 1 ;
        if(rec(k+1,(s*10+v)%7) == 0) aoki = 0 ; 
        if(rec(k+1,(s*10+0)%7) == 0) aoki = 0 ;
        return dp[k][s] = aoki ;
    }
    else{
        int takahashi = 0 ;
        if(rec(k+1,(s*10+v)%7) == 1) takahashi = 1 ;
        if(rec(k+1,(s*10+0)%7) == 1) takahashi = 1 ;
        return dp[k][s] = takahashi ;
    }
}

int main(){
    cin >> n >> S >> X ;
    rep(i,n+1) rep(j,7) dp[i][j] = -1 ;
    rep(i,7) dp[n][i] = 0 ; dp[n][0] = 1 ;
    int res = rec(0,0) ;
    if(res == 1) cout << "Takahashi" << endl ;
    else cout << "Aoki" << endl ;
}