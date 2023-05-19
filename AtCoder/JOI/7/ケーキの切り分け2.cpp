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
ll A[2020] ;
ll dp[2020][2020] ;

ll rec(ll x , ll y){
    if(x == y) return dp[x][y] = A[x] ;
    if((x + 1) % n == y) return dp[x][y] = max(A[x],A[y]) ;
    if(dp[x][y] != -1) return dp[x][y] ;
    ll a , b ;
    if(A[(x+1)%n] > A[y]) a = rec((x+2)%n,y) + A[x] ;
    else a = rec((x+1)%n,(y-1+n)%n) + A[x];
    if(A[x] > A[(y-1+n)%n]) b = rec((x+1)%n,(y-1+n)%n) + A[y] ;
    else b = rec(x,(y-2+n)%n) + A[y];
    return dp[x][y] = max(a,b) ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    if(n == 1){
        cout << A[0] << endl ;
        return 0 ;
    }
    if(n == 2){
        cout << max(A[0],A[1]) << endl ;
        return 0 ;
    }
    rep(i,n) rep(j,n) dp[i][j] = -1 ;
    ll res = 0  ;
    rep(i,n) {
        int x = (i + 1) % n , y = (i - 1 + n) % n ;
        if(A[x] > A[y]) chmax(res,rec((i+2)%n,y)+A[i]) ;
        else chmax(res,rec((i+1)%n,(y-1+n)%n)+A[i]) ;
    }
    cout << res << endl ;
}