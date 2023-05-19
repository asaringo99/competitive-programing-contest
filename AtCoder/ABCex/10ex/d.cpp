#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

struct Dinic{
    private:
        static const ll inf = LLONG_MAX;
        struct edge {
            int to, rev;
            ll cap ;
        };

        struct edge_ {
            int from, to;
            ll cap, flow ;
        };

        int n;
        vector<vector<edge>> G ;
        vector<pair<int,int>> pos;
        vector<int> level, iter;

        void init_(int n){
            G.resize(n);
            iter.resize(n);
            level.resize(n);
        }

        void add_edge_(int from , int to , ll cap){
            pos.push_back({from, G[from].size()});
            int from_id = int(G[from].size());
            int to_id = int(G[to].size());
            if (from == to) to_id++;
            G[from].push_back(edge{to, to_id, cap}) ;
            G[to].push_back(edge{from, from_id, 0}) ;
        }

        int edge_size_(){
            return (int)pos.size();
        }

        edge_ get_edge_(int k){
            edge e = G[pos[k].first][pos[k].second];
            edge re = G[e.to][e.rev];
            return edge_{pos[k].first, e.to, e.cap + re.cap, re.cap};
        }

        vector<edge_> get_edges_(){
            int m = (int)pos.size();
            vector<edge_> res;
            for(int i = 0; i < m; i++) res.push_back(get_edge_(i));
            return res;
        }

        void change_edge_(int k, ll cap, ll flow){
            edge &e = G[pos[k].first][pos[k].second];
            edge &re = G[e.to][e.rev];
            e.cap = cap - flow;
            re.cap = flow;
        }

        void bfs(int s){
            fill(level.begin(),level.end(),-1) ;
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

        ll max_flow_(int s , int t, ll flow_limit){
            ll flow = 0 ;
            for(;;){
                bfs(s) ;
                if(level[t] == -1) return flow ;
                fill(iter.begin(),iter.end(),0) ;
                ll f = dfs(s,t,flow_limit-flow);
                while(f > 0){
                    flow += f ;
                    f = dfs(s,t,flow_limit-flow);
                }
            }
        }

        vector<bool> min_cut_(int s){
            vector<bool> res(n,false);
            queue<int> que;
            que.push(s);
            while(!que.empty()){
                int p = que.front(); que.pop();
                res[p] = true;
                for(edge e : G[p]){
                    if(e.cap > 0 && !res[e.to]){
                        res[e.to] = true;
                        que.push(e.to);
                    }
                }
            }
            return res;
        }

    public:
        Dinic() {}
        Dinic(int n_): n(n_) { init_(n); }
        void init(int n) { init_(n); }
        int edge_size() { return edge_size_(); }
        void add_edge(int from , int to , ll cap) { add_edge_(from, to, cap); }
        edge_ get_edge(int k) { return get_edge_(k); }
        vector<edge_> get_edges() { return get_edges_(); }
        void change_edge(int k, ll cap, ll flow) { change_edge_(k, cap, flow); }
        ll max_flow(int s , int t, ll flow_limit = inf){ return max_flow_(s,t,flow_limit) ; }
        vector<bool> min_cut(int s) { return min_cut_(s); }
};

// function                           : return                : description
// --------------------------------------------------------------------------------------------------------
// constructor()                      :                       : 
// constructor(n)                     :                       : サイズ n で初期化する
// init(int n)                        : void                  : サイズ n で初期化する
// add_edge(int from, int to, ll cap) : void                  : 容量が cap の from から to への辺を張る
// edge_size()                        : int                   : 辺のサイズを返す
// get_edge(int k)                    : void                  : k 番目の辺の情報(始点, 行き先, 容量, 流量)を返す
// get_edges()                        : vector<edge_>         : 全ての辺の情報(始点, 行き先, 容量, 流量)を返す
// change_edge(int k)                 : void                  : k 番目の辺を変更する
// max_flow(int s, int t)             : ll                    : s から t への最大流量を返す
// min_cut(int s)                     : vector<bool>          : 最小カットを構成する集合 S を true にして返す
// --------------------------------------------------------------------------------------------------------

int n, k, m;

int main(){
    fast_io
    cin >> n >> k >> m;
    vector<int> A(k);
    rep(i,k) cin >> A[i];
    Dinic dinic(n+k+2);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        dinic.add_edge(a,b,1);
        dinic.add_edge(b,a,1);
    }
    dinic.add_edge(n+k,0,n);
    rep(i,k){
        dinic.add_edge(A[i],i+n,1);
        dinic.add_edge(i+n,n+k+1,1);
    }
    int res = dinic.max_flow(n+k,n+k+1);
    cout << res << endl;
}