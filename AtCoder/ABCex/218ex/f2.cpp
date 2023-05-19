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
    ll cost ;
};

int n , m ;

vector<edge> G[202020] ;
ll d[202020] ;
int prevv[202020] ; // 一個前のノード
vector<int> line ; // 経路復元
map<P,bool> mp ;
P E[202020] ;

// 始点: s , 終点: t
void djikstra(int s , int t , P pp){
    rep(i,n) d[i] = 1e16 ;
    rep(i,n) prevv[i] = -1 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(pp == P(v,e.to)) continue ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                prevv[e.to] = v ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
    // 始点から終点までの経路を復元する
    int v = t ;
    if(pp == P(-1,-1)) while(v != -1){
        line.push_back(v) ;
        mp[P(prevv[v],v)] = true ;
        v = prevv[v] ;
    }
    reverse(line.begin(),line.end()) ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(edge{u,1}) ;
        E[i] = P(v,u) ;
    }
    djikstra(0,n-1,P(-1,-1)) ;
    ll res = d[n-1] ;
    rep(i,m){
        if(mp[E[i]]) {
            djikstra(0,n-1,E[i]) ;
            int ans = d[n-1] == 1e16 ? -1 : d[n-1] ;
            cout << (d[n-1] == 1e16 ? -1 : d[n-1]) << endl ;
        }
        else cout << (res == 1e16 ? -1 : res) << endl ;
    }
}