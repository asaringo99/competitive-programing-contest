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
vector<int> G[101010] ;
ll dp[101010] ;
ll A[101010] ;

void dfs(int v , int prev){
    ll res = A[v] ;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v) ;
        if(dp[u] > 0) res += dp[u] ;
    }
    dp[v] = res ;
}

int main(){
    cin >> n ;
    rep(i,n){
        int p , w ;
        cin >> p >> w ;
        if(p != 0){
            p-- ;
            G[i].push_back(p) ;
            G[p].push_back(i) ;
        }
        A[i] = w ;
    }
    ll res = -1e18 ;
    dfs(0,-1) ;
    rep(i,n) chmax(res,dp[i]) ;
    cout << res << endl ;
}