#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to;
    ll cost ;
};

vector<edge> G[303030] ;
ll dp[303030][2] ;

int n ;
int d[303030] ;

void dfs(int v , int prev){
    ll res = 0 ;
    priority_queue<TP> Q , que ;
    for(edge e : G[v]){
        int u = e.to ;
        ll cost = e.cost ;
        if(u == prev) continue;
        dfs(u,v) ;
        que.push({cost+dp[u][1]-dp[u][0],cost,dp[u][0],dp[u][1]}) ;
    }
    int cnt = 0 ;
    Q = que ;
    while(!que.empty()){
        auto [mag,cost,fir,sec] = que.top() ; que.pop() ;
        if(cnt == d[v]){
            dp[v][0] += fir ;
            continue;
        }
        if(mag <= 0) {
            dp[v][0] += fir ;
            continue;
        }
        cnt++ ;
        if(cnt <= d[v]) dp[v][0] += sec + cost ;
    }

    if(d[v] == 0) {
        dp[v][1] = -1e16 ;
        return ;
    }
    
    que = Q ;
    cnt = 0 ;
    while(!que.empty()){
        auto [mag,cost,fir,sec] = que.top() ; que.pop() ;
        if(cnt == d[v] - 1){
            dp[v][1] += fir ;
            continue;
        }
        if(mag <= 0) {
            dp[v][1] += fir ;
            continue;
        }
        cnt++ ;
        if(cnt <= d[v] - 1) dp[v][1] += sec + cost ;
    }
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> d[i] ;
    rep(i,n-1){
        int u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    dfs(0,-1) ;
    cout << dp[0][0] << endl ;
}