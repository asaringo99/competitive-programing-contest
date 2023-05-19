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

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to;
    int id;
};


int n , m ;

ll d[2020];
pair<int,int> prevv[2020];

void bfs(int s, vector<vector<edge>>&G){
    rep(i,n) d[i] = 1e16 ;
    d[s] = 0 ;
    queue<int> que ;
    que.push(s) ;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i];
            int u = e.to;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                prevv[u] = {v,e.id};
                que.push(u) ;
            }
        }
    }
}

vector<vector<edge>> G;
vector<int> get_path(int s, int g){
    vector<int> path;
    while(g != s){
        path.push_back(prevv[g].second);
        g = prevv[g].first;
    }
    return path;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> V;
    G = vector<vector<edge>>(n);
    vector<vector<bool>> go(n,vector<bool>(n,false));
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        V.push_back({a,b,i});
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        go[a][b] = true;
        go[b][a] = true;
    }
    rep(i,m){
        vector<vector<edge>> F(n);
        rep(j,m){
            if(i == j) continue;
            auto[a,b,id] = V[j];
            F[a].push_back({b,id});
            F[b].push_back({a,id});
        }
        auto[a,b,id] = V[i];
        bfs(a,F);
        if(G[a].size() > 3){
            int g = -1;
            int dist = 1e9;
            rep(j,n) {

                if(dist > d[j]){
                    dist = d[j];
                    g = j;
                }
            }

            if(ok){
                cout << "YES" << endl;
                cout << 2 + res.size() << endl;
                set<int> st;
                for(int u : res) {
                    st.insert(u);
                    auto[x,y] = V[u];
                    cout << x + 1 << " " << y + 1 << endl;
                }
                int cnt = 0;
                for(auto[u,id] : F[i]){
                    if(st.count(id)) continue;
                    if(cnt == 2) continue;
                    auto[x,y] = V[id];
                    cout << x + 1 << " " << y + 1 << endl;
                    cnt++;
                }
                return;
            }
        }
    }
    cout << "NO" << endl ;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}