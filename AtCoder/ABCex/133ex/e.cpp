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

const int mod = 1000000007 ;

ll n , k ;
ll dp[101010] ;
ll res ;

vector<int> G[101010] ;

void dfs(int v , int prev){
    ll c = k ;
    if(v == 0) res *= c-- ;
    else c -= 2 ;
    res %= mod ;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v) ;
        res *= c-- ;
        res %= mod ;
    }
}

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    res = 1 ;
    dfs(0,-1) ;
    cout << res << endl ;
}