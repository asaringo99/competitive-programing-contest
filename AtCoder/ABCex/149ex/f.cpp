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

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
vector<int> G[201010] ;
ll res = 0 ;
ll dp[202020] ;

void dfs(int v , int prev){
    ll sum = 0 , cnt = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        cnt += dp[u] ;
        (sum += (powmod(2,dp[u]) - 1 + mod) % mod) %= mod ;
    }
    (sum += (powmod(2,n-cnt) - 1 + mod) % mod) %= mod ;
    (res += (powmod(2,n-1) - sum - 1 + mod) % mod) %= mod ;
    dp[v] = cnt ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    cout << res * powmod(powmod(2,mod-2),n) % mod << endl ;
}