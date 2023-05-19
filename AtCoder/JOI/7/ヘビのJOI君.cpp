#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,int,int,int> TP ;
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
    ll cost;
};

int n , m , x ;
vector<edge> G[10101] ;
int T[10101] ;
ll d[10101][2][202] ;

void djikstra(){
    rep(i,n) rep(j,2) rep(k,x+1) d[i][j][k] = 1e18 ;
    d[0][0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0,0}) ;
    while(!que.empty()){
        auto[dist,v,type,t] = que.top() ; que.pop() ;
        if(dist > d[v][type][t]) continue;
        for(edge e : G[v]){
            int u = e.to ;
            ll cost = e.cost ;
            // 寒すぎる -> 暑すぎる
            if(T[u] == 1 && type == 0){
                if(t + cost < x) continue;
                if(d[u][1][0] <= d[v][0][t] + cost) continue;
                d[u][1][0] = d[v][0][t] + cost ;
                que.push({d[u][1][0],u,1,0}) ;
            }
            // 暑すぎる -> 寒すぎる
            if(T[u] == 0 && type == 1){
                if(t + cost < x) continue;
                if(d[u][0][0] <= d[v][1][t] + cost) continue;
                d[u][0][0] = d[v][1][t] + cost ;
                que.push({d[u][0][0],u,0,0}) ;
            }
            // 寒すぎる -> 寒すぎる
            if(T[u] == type){
                if(d[u][type][0] <= d[v][type][t] + cost) continue;
                d[u][type][0] = d[v][type][t] + cost ;
                que.push({d[u][type][0],u,type,0}) ;
            }
            if(T[u] == 2){
                int c = t + cost > x ? x : t + cost ;
                if(d[u][type][c] <= d[v][type][t] + cost) continue;
                d[u][type][c] = d[v][type][t] + cost ;
                que.push({d[u][type][c],u,type,c}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> x ;
    rep(i,n) cin >> T[i];
    rep(i,n){
        if(T[i] == 1) T[i] = 2 ;
        else if(T[i] == 2) T[i] = 1 ;
    }
    rep(i,m){
        int u , v ;
        ll c ;
        cin >> u >> v >> c ;
        u-- ; v-- ;
        G[u].push_back(edge{v,c}) ;
        G[v].push_back(edge{u,c}) ;
    }
    djikstra() ;
    ll res = 1e18 ;
    rep(i,2) rep(j,x+1) chmin(res,d[n-1][i][j]) ;
    cout << res << endl ;
}