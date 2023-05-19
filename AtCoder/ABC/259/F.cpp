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

struct edge
{
    int to ;
    ll cost ;
};

int n ;
int d[303030] ;

vector<edge> G[303030] ;
ll dp[303030] ;

ll dfs(int v , int prev){
    ll res = 0 ;
    priority_queue<ll,vector<ll>,greater<ll>> que ;
    for(edge e : G[v]){
        int u = e.to ;
        ll cost = e.cost ;
        if(u == prev) continue;
        ll sum = dfs(u,v) ;
        if(sum + cost > 0) {
            res += sum + cost ;
            que.push(sum + cost) ;
        }
        if(que.size() > d[v]) {
            res -= que.top() ;
            que.pop() ;
        }
    }
    cout << v << endl ;
    while(!que.empty()){
        cout << que.top() << " " ; que.pop() ;
    }
    cout << endl ;
    dp[v] = res ;
    return res ;
}

TP E[303030] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> d[i] ;
    rep(i,n-1){
        int u , v ,w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        E[i] = {w,u,v} ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    // dfs(0,-1) ;
    sort(E,E+n,greater<TP>()) ;
    ll res = 0 ;
    rep(i,n){
        auto [val,u,v] = E[i] ;
        if(d[u] == 0 || d[v] == 0) continue;
        res += val ;
        d[u]-- ;
        d[v]-- ;
    }
    cout << res << endl ;
}