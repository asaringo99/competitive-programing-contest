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

int n , m ;
char S[2020] , T[2020] ;
ll dp[2020][2020][2] ;

inline ll rec(int x , int y , int k){
    if(x > n || y > m) return 0 ;
    if(x == n && y == m) return 0 ;
    if(dp[x][y][k] != -1e8) return dp[x][y][k] ;
    ll res = 0 ;
    if(k == 1){
        if(x < n) if(S[x] == 'I') chmax(res,1+rec(x+1,y,0)) ;
        if(y < m) if(T[y] == 'I') chmax(res,1+rec(x,y+1,0)) ;
    }
    if(k == 0){
        if(x < n) if(S[x] == 'O') chmax(res,1+rec(x+1,y,1)) ;
        if(y < m) if(T[y] == 'O') chmax(res,1+rec(x,y+1,1)) ;
        if(res % 2 == 1) res-- ;
    }
    return dp[x][y][k] = res ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> S[i] ;
    rep(i,m) cin >> T[i] ;
    rep(i,n+1) rep(j,m+1) rep(k,2) dp[i][j][k] = -1e8 ;
    ll res = 0 ;
    rep(i,n) rep(j,m) chmax(res,rec(i,j,1)) ;
    cout << res << endl ;
}