#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
vector<ll> X , A ;
ll dp[202020][101] ;

ll rec1(int v , int k){
    if(dp[v][k] != -1) return dp[v][k] ;

    ll res = max(X[v]+A[v],dp[v][k-1]) ;
    auto it = lower_bound(X.begin(),X.end(),X[v]+A[v]) ;
    if(*it == X[v]+A[v]){
        int u = it - X.begin() ;
        chmax(res,rec1(u,k)) ;
    }
    return dp[v][k] = res ;
}

ll rec2(int v , int k){
    if(dp[v][k] != -1) return dp[v][k] ;

    ll res = max(dp[v][k-1],dp[v][k-2]) ;
    auto jt = lower_bound(X.begin(),X.end(),X[v]-A[v]) ;
    if(*jt == X[v]-A[v]){
        int u = jt - X.begin() ;
        chmax(res,rec2(u,k)) ;
    }
    return dp[v][k] = res ;
}

int main(){
    fast_input_output
    cin >> n ;
    X.resize(n+1) ;
    A.resize(n+1) ;
    rep(i,n) cin >> X[i] ;
    rep(i,n) cin >> A[i] ;
    X[n] = 1e16 ;
    rep(i,n) rep(j,100) dp[i][j] = -1 ;
    for(int i = 0 ; i <= 40 ; i++){
        rep(j,n) rec1(j,2*i+1) ;
        rep(j,n) rec2(j,2*i+2) ;
    }
    rep(i,n) cout << max(dp[i][6],dp[i][6]) - X[i] << endl ;
}