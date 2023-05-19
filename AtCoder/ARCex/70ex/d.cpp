#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
int A[5050] ;
bool dp[5050][5050] ;
bool use[5050] ;
P pre[5050][5050] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n,greater<int>()) ;
    rep(i,n+1) rep(j,k+1) pre[i][j] = P(-1,-1) ;
    dp[0][0] = true ;
    pre[0][0] = P(-1,-1) ;
    rep(i,n) rep(j,k) if(dp[i][j]){
        int t = j + A[i] >= k ? k : j + A[i] ;
        dp[i+1][j] = true ;
        dp[i+1][t] = true ;
        pre[i+1][j] = pre[i][j] ;
        pre[i+1][t] = P(i,j) ;
    }
    for(int a = n ; a > 0 ; a--){
        P p = pre[a][k] ;
        int i = p.first , j = p.second ;
        while(!(i == -1 && j == -1)){
            use[i] = true ;
            P p = pre[i][j] ;
            i = p.first , j = p.second ;
        }
    }
    int res = 0 ;
    rep(i,n) if(!use[i]) res++ ;
    cout << res << endl ;
}