#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

struct Dinic{
    private:
        static const ll inf = LLONG_MAX;
        struct edge {
            int to , rev ;
            ll cap ;
        };

        struct edge_ {
            int to , rev ;
            ll cap, flow ;
        };

        int n;
        vector<vector<edge>> G ;
        vector<pair<int,int>> pos;
        vector<int> level, iter;

        void init_(int n_){
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


bool is_prime(int x){
    for(int i = 2 ; i * i <= x ; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int n ;
vector<int> A, B;
vector<int> C, D;

int main(){
    fast_input_output
    cin >> n ;
    Dinic dnc(n+2);
    int id = -1, cap = 0;
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        if(x % 2 == 0){
            A.push_back(x);
            B.push_back(y);
        }
        else{
            if(x == 1) {
                id = C.size();
                cap = y;
                C.push_back(x);
                D.push_back(0);
            }
            else{
                C.push_back(x);
                D.push_back(y);
            }
        }
    }
    int e = A.size(), o = C.size();
    rep(i,e) rep(j,o){
        if(is_prime(A[i]+C[j])) dnc.add_edge(i,e+j,1e18);
    }
    rep(i,e){
        dnc.add_edge(n,i,B[i]);
    }
    rep(i,o){
        if(i == id){
            id = dnc.edge_size();
        }
        dnc.add_edge(e+i,n+1,D[i]);
    }
    ll res = dnc.max_flow(n,n+1);
    if(id != -1){
        dnc.change_edge(id,cap,0);
        res += dnc.max_flow(n,n+1);
        auto[to,rev,cap,flow] = dnc.get_edge(id);
        int cnt = cap - flow;
        res += cnt / 2;
    }
    cout << res << endl;
}