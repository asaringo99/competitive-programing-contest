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
ll dp[1 << 20] ;
int A[101010] , B[22] , S[101010][22] ;

int main(){
    cin >> n >> m ;
    rep(i,n){
        cin >> A[i] ;
        A[i]-- ;
        B[A[i]]++ ;
    }
    rep(i,n){
        rep(j,m){
            S[i+1][j] = S[i][j] ;
        }
        S[i+1][A[i]]++ ;
    }
    rep(i,1<<m) dp[i] = 1e18 ;
    dp[0] = 0 ;
    rep(T,1<<m){
        int sum = 0 ;
        rep(i,m) if(T >> i & 1) sum += B[i] ;
        rep(i,m) if(!(T >> i & 1)){
            chmin(dp[T | (1 << i)] , dp[T] + B[i] - (S[sum+B[i]][i] - S[sum][i])) ;
        }
    }
    cout << dp[(1 << m) - 1] << endl ;
}