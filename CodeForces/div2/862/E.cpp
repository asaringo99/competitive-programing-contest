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

vector<vector<int>> G;
vector<int> A;
vector<int> used;

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数
        vector<set<pair<int,int>>> ques; // 次に訪れるべき辺

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            ques.resize(n);
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
                for(int u: G[i]) ques[i].insert({A[u],u});
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
                if(ques[x].size() > ques[y].size()) swap(ques[x],ques[y]);
                for(auto[a,u] : ques[x]) ques[y].insert({a,u});
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
                if(ques[y].size() > ques[x].size()) swap(ques[x],ques[y]);
                for(auto[a,u] : ques[y]) ques[x].insert({a,u});
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
        pair<int,int> next_node(int x){
            while(!ques[root(x)].empty()){
                auto it = ques[root(x)].begin();
                auto[a,v] = *it;
                if(same(x,v)) {
                    ques[root(x)].erase(it);
                    continue;
                }
                // cout << x << " " << a << endl;
                return {a,v};
            }
            return {-1,-1};
        }
};


void solve(){
    int n, m;
    cin >> n >> m;
    G = vector<vector<int>>(n);
    A = vector<int>(n);
    used = vector<int>(n,-1);
    rep(i,n) cin >> A[i];
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    queue<int> Q;
    rep(i,n) if(A[i] == 0) Q.push(i);
    UnionFind uf(n);
    while(!Q.empty()){
        int s = Q.front(); Q.pop();
        while(1){
            auto [a, nxt] = uf.next_node(s);
            // cout << nxt << " " << a << endl;
            if(nxt == -1) break;
            if(a > uf.size(s)) break;
            uf.unite(s,nxt);
        }
    }
    if(uf.size(0) == n) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}