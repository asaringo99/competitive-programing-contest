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

struct edge{
    int to ;
    int cost ;
};

int n , m ;
int X[101] , Y[101] ;
vector<edge> G[101] ;

ll d[101][101] ;

bool dot(int v , int from , int to){
    if(from == -1) return true ;
    ll x = X[to] - X[v] , y = Y[to] - Y[v] ;
    ll s = X[from] - X[v] , t = Y[from] - Y[v] ;
    if(x*s+y*t>0) return false ;
    else return true ;
}

void djikstra(){
    rep(i,n) rep(j,n) d[i][j] = 1e16 ;
    d[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0}) ;
    while(!que.empty()){
        auto [dist,v,from] = que.top() ; que.pop() ;
        if(d[v][from] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to][v] > d[v][from] + e.cost && dot(v,from,e.to)){
                d[e.to][v] = d[v][from] + e.cost ;
                que.push({d[e.to][v],e.to,v}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    djikstra() ;
    ll res = 1e16 ;
    rep(i,n) chmin(res,d[1][i]) ;
    if(res == 1e16) res = -1 ;
    cout << res << endl ;
}