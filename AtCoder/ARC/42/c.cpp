#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , p ;
P X[5050] ;
ll dp[5050][5050] ;

int main(){
    cin >> n >> p ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    sort(X,X+n,greater<P>()) ;
    rep(i,n){
        int x = X[i].first , v = X[i].second ;
        rep(j,p+2){
            chmax(dp[i+1][j], dp[i][j]) ;
            int k = j + x > p ? p + 1 : j + x ;
            if(j != p + 1) chmax(dp[i+1][k], dp[i][j] + v) ;
        }
    }
    ll res = 0 ;
    rep(i,p+2) chmax(res,dp[n][i]) ;
    cout << res << endl ;
}