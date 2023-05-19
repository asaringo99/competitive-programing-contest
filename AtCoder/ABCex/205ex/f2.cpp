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

const int MAX_N = 10007 ;

struct Dinic{
    struct edge
    {
        int to , rev ;
        ll cap ;
    };

    vector<edge> G[MAX_N] ;
    int level[MAX_N] , iter[MAX_N] ;

    void add_edge(int from , int to , ll cap){
        G[from].push_back(edge{to,(int)G[to].size(),cap}) ;
        G[to].push_back(edge{from,(int)G[from].size()-1,0}) ;
    }

    void bfs(int s){
        memset(level,-1,sizeof(level)) ;
        level[s] = 0 ;
        queue<int> que ;
        que.push(s) ;
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            for(int i = 0 ; i < G[v].size() ; i++){
                edge e = G[v][i] ;
                if(e.cap > 0 && level[e.to] == -1){
                    level[e.to] = level[v] + 1 ;
                    que.push(e.to) ;
                }
            }
        }
    }

    inline ll dfs(int v , int t , ll f){
        if(v == t) return f ;
        for(int &i = iter[v] ; i < G[v].size() ; i++){
            edge &e = G[v][i] ;
            if(e.cap > 0 && level[e.to] > level[v]){
                ll d = dfs(e.to,t,min(f,e.cap)) ;
                if(d > 0){
                    e.cap -= d ;
                    G[e.to][e.rev].cap += d ;
                    return d ;
                }
            }
        }
        return 0 ;
    }

    ll max_flow(int s , int t){
        ll flow = 0 ;
        for(;;){
            bfs(s) ;
            if(level[t] == -1) return flow ;
            ll f ;
            memset(iter,0,sizeof(iter)) ;
            while((f = dfs(s,t,LLONG_MAX)) > 0){
                flow += f ;
            }
        }
    }

    ll getMaxFlow(int s , int t){ return max_flow(s,t) ; }
};

int H , W , n ;

int main(){
    cin >> H >> W >> n ;
    Dinic flow ;
    rrep(x,1,H+1) flow.add_edge(0,x,1) ;
    rrep(y,1,W+1) flow.add_edge(H+y,H+W+2*n+1,1) ;
    rep(i,n){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        rrep(x,a,c+1) flow.add_edge(x,H+W+i+1,1) ;
        flow.add_edge(H+W+i+1,H+W+n+i+1,1) ;
        rrep(y,b,d+1) flow.add_edge(H+W+n+i+1,H+y,1) ;
    }
    cout << flow.getMaxFlow(0,H+W+2*n+1) << endl ;
}