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
ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

struct edge{
    int to ;
    ll cost ;
};

int n ;
vector<edge> G[202020];
ll d[202020] ;
vector<ll> vec(60,0) ;

void dfs(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(e.to == prev) continue;
        d[e.to] = d[v] ^ e.cost ;
        dfs(e.to,v) ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int u , v ;
        ll w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    dfs(0,-1) ;
    rep(i,n) rep(j,60) if(d[i] >> j & 1) vec[j]++ ;
    ll res = 0 ;
    rep(i,60) (res += vec[i] * (ll)(n - vec[i]) % mod * powmod(2,i) % mod) %= mod ;
    cout << res % mod << endl ;
}