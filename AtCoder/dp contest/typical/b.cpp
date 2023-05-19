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

int a , b ;
int A[1010] , B[1010] ;
ll dp[1010][1010] ;

ll rec(int x , int y){
    if(x == a && y == b) return dp[x][y] = 0 ;
    if(x == a) return dp[x][y] = B[y] - rec(x,y+1) ;
    if(y == b) return dp[x][y] = A[x] - rec(x+1,y) ;
    if(dp[x][y] != -1) return dp[x][y] ;
    ll res = max(A[x]-rec(x+1,y),B[y]-rec(x,y+1)) ;
    return dp[x][y] = res ;
}

int main(){
    cin >> a >> b ;
    ll sum = 0 ;
    rep(i,a) cin >> A[i] , sum += A[i] ;
    rep(i,b) cin >> B[i] , sum += B[i] ;
    rep(i,a) rep(j,b) dp[i][j] = -1 ;
    cout << (rec(0,0) + sum) / 2 << endl ;
}