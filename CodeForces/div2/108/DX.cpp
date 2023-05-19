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

struct MinCostFlow{
    
    private:
        static const ll inf = LLONG_MAX;
        struct edge
        {
            int to , rev ;
            ll cost , cap ;
        };

        struct edge_ {
            int from, to;
            ll cap, flow , cost;
        };

        int n;
        vector<vector<edge>> G ;
        vector<pair<int,int>> pos;
        vector<ll> dist , h;
        vector<int> prevv , preve ;

        void init_(int n_){
            G.resize(n_);
            dist.resize(n_);
            h.resize(n_);
            prevv.resize(n_);
            preve.resize(n_);
        }

        void add_edge_(int from, int to, ll cap, ll cost){
            pos.push_back({from, G[from].size()});
            int from_id = int(G[from].size());
            int to_id = int(G[to].size());
            if (from == to) to_id++;
            G[from].push_back(edge{to, to_id, cost, cap}) ;
            G[to].push_back(edge{from, from_id, -cost, 0}) ;
        }

        int edge_size_(){
            return (int)pos.size();
        }

        edge_ get_edge_(int k){
            edge e = G[pos[k].first][pos[k].second];
            edge re = G[e.to][e.rev];
            return edge_{pos[k].first, e.to, e.cap + re.cap, re.cap, e.cost};
        }

        vector<edge_> get_edges_(){
            int m = (int)pos.size();
            vector<edge_> res;
            for(int i = 0; i < m; i++) res.push_back(get_edge_(i));
            return res;
        }

        vector<pair<ll,ll>> min_flow_(int s, int t, ll flow_limit){
            vector<pair<ll,ll>> res = {{0,0}};
            ll flow = 0;
            ll cost = 0 ;
            ll prev_cost_per_flow = -1;
            fill(h.begin(), h.end(),0);
            while(flow < flow_limit){
                fill(dist.begin(),dist.end(),9223372036854775807LL) ;
                priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que ;
                dist[s] = 0 ;
                que.push(pair<ll,int>(0,s)) ;
                while(!que.empty()){
                    pair<ll,int> p = que.top() ; que.pop() ;
                    int v = p.second ;
                    if(dist[v] < p.first) continue ;
                    for(int i = 0 ; i < G[v].size() ; i++){
                        edge e = G[v][i] ;
                        if(e.cap > 0 && dist[e.to] > dist[v] + h[v] - h[e.to] + (G[e.to][e.rev].cap > 0 ? 0 : e.cost)){
                            dist[e.to] = dist[v] + h[v] - h[e.to] + (G[e.to][e.rev].cap > 0 ? 0 : e.cost);
                            prevv[e.to] = v ;
                            preve[e.to] = i ;
                            que.push(P(dist[e.to],e.to)) ;
                        }
                    }
                }
                if(dist[t] == inf) break; // 総流量fを流すことができなかった
                for(int i = 0 ; i < n ; i++) h[i] += dist[i] ;
                ll d = flow_limit - flow ;
                for(int v = t ; v != s ; v = prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap) ;
                for(int v = t ; v != s ; v = prevv[v]){
                    edge &e = G[prevv[v]][preve[v]] ;
                    e.cap -= d ;
                    G[e.to][e.rev].cap += d ;
                }
                cost += h[t] * d;
                flow += d;
                if(prev_cost_per_flow == h[t]) res.pop_back();
                res.push_back({flow, cost});
                prev_cost_per_flow = h[t];
            }
            return res ;
        }
    
    public:
        MinCostFlow() {}
        MinCostFlow(int n_): n(n_) { init_(n); }
        void init(int n) { init_(n); }
        int edge_size() { return edge_size_(); }
        void add_edge(int from , int to , ll cap, ll cost) { add_edge_(from, to, cap, cost); }
        edge_ get_edge(int k) { return get_edge_(k); }
        vector<edge_> get_edges() { return get_edges_(); }
        ll min_cost(int s, int t, ll flow_limit = inf){ return min_flow_(s,t,flow_limit).back().second; }
        pair<ll,ll> min_cost_flow(int s, int t, ll flow_limit = inf){ return min_flow_(s,t,flow_limit).back(); }
        vector<pair<ll,ll>> slope(int s, int t, ll flow_limit = inf){ return min_flow_(s,t,flow_limit); }
};

void solve(){
    int n, m;
    int k = 0;
    cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m,1));
    vector<vector<char>> C(n,vector<char>(m));
    rep(i,n) rep(j,m) cin >> C[i][j];
    vector<int> vec;
    rep(i,n) rep(j,m) if(C[i][j] == '#'){
        k++;
        vec.push_back(i*m+j);
        A[i][j] = 0;
    }
    ll ans = 1e18;
    string S = "";
    rep(q,vec.size()){
        int z = vec[q];
        MinCostFlow mcf(2*n*m+2);
        rep(i,n){
            rep(j,m){
                int p = i * m + j;
                mcf.add_edge(2*p,2*p+1,1000,A[i][j]);
                if(i < n - 1){
                    int q = (i + 1) * m + j;
                    mcf.add_edge(2*p+1,2*q,1000,0);
                    mcf.add_edge(2*q+1,2*p,1000,0);
                }
                if(j < m - 1){
                    int q = i * m + j + 1;
                    mcf.add_edge(2*p+1,2*q,1000,0);
                    mcf.add_edge(2*q+1,2*p,1000,0);
                }
            }
        }
        rep(i,k){
            int p = vec[i];
            mcf.add_edge(2*p+1,2*n*m+1,1,0);
        }
        mcf.add_edge(2*n*m,2*z,1000,0);
        ll res = mcf.min_cost(2*n*m,2*n*m+1);
        chmin(ans,res);
    }
    cout << ans << endl;
}

int main(){
    fast_io
    solve();
}