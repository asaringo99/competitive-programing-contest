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

int n , m ;
vector<int> G[606] ;
ld dp[606] ;

ld rec(int v , int p){
    if(v == n-1) return dp[v] = 0 ;
    if(G[v].size() == 0) return dp[v] = 1e18 ;
    if(dp[v] >= 0) return dp[v] ;
    ld res = 0 , cnt = G[v].size() , maxval = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        ld val = rec(u,p) ;
        res += val ;
        chmax(maxval,val) ;
    }
    if(v == p) cnt-- , res -= maxval ;
    if(cnt == 0) return dp[v] = 1e18 ;
    return dp[v] = res / cnt + 1 ;
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    ld res = 1e18 ;
    rep(i,n){
        rep(j,n) dp[j] = -1 ;
        chmin(res,rec(0,i)) ;
    }
    cout << fixed << setprecision(25) << res << endl ;
}