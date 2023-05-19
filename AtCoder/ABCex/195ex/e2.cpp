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
int dp[202020][10] ;

int rec(int k , int s){
    if(dp[k][s] != -1) return dp[k][s] ;
    if(k == n){
        if(s == 0) return dp[k][s] = 1 ;
        else return dp[k][s] = 0 ;
    }
    int x = S[k] - '0' ;
    if(X[k] == 'A'){
        if(rec(k+1,(s*10+x)%7) == 0) return dp[k][s] = 0 ;
        if(rec(k+1,(s*10)%7) == 0) return dp[k][s] = 0 ;
        return dp[k][s] = 1 ;
    }
    else{
        if(rec(k+1,(s*10+x)%7) == 1) return dp[k][s] = 1 ;
        if(rec(k+1,(s*10)%7) == 1) return dp[k][s] = 1 ;
        return dp[k][s] = 0 ;
    }
}

int main(){
    cin >> n >> S >> X ;
    rep(i,n+1) rep(j,10) dp[i][j] = -1 ;
    if(rec(0,0) == 1) cout << "Takahashi" << endl ;
    else cout << "Aoki" << endl ;
}