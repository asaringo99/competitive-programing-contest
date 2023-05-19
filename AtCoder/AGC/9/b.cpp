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

void dfs(int v , int prev){
    ll res = G[v].size() ;
    vector<ll> vec ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        vec.push_back(dp[u]+1) ;
        chmax(res,dp[u]+1) ;
    }
    sort(vec.begin(), vec.end()) ;
    for(int i = 1 ; i < vec.size() ; i++){
        if(vec[i] <= vec[i-1]) vec[i] = vec[i-1] + 1 ;
        chmax(res,vec[i]) ;
    }
    dp[v] = res ;
}

int main(){
    cin >> n ;
    rrep(i,1,n){
        int a ;
        cin >> a ;
        a-- ;
        G[a].push_back(i) ;
    }
    dfs(0,-1) ;
    cout << dp[0] << endl ;
}