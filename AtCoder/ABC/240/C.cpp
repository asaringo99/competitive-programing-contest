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

int n , x ;
bool dp[101][10101] ;
int A[101] , B[101] ;

int main(){
    cin >> n >> x ;
    rep(i,n) cin >> A[i] >> B[i] ;
    dp[0][0] = true ;
    rep(i,n){
        rep(j,x) if(dp[i][j]) {
            if(j + A[i] <= x) dp[i+1][j+A[i]] = true ;
            if(j + B[i] <= x) dp[i+1][j+B[i]] = true ;
        }
    }
    if(dp[n][x]) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}