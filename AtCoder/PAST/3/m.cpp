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

int n, m, k;
vector<int> G[101010];

map<int,vector<ll>> d;

void djikstra(int s){
    d[s].resize(n,1e16);
    d[s][s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        auto[dist, v] = que.top(); que.pop() ;
        if(d[s][v] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[s][u] > d[s][v] + 1){
                d[s][u] = d[s][v] + 1 ;
                que.push(P(d[s][u],u)) ;
            }
        }
    }
}

ll dp[1<<17][17];

int main(){
    fast_io
    cin >> n >> m;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    int s;
    cin >> s >> k;
    s--;
    djikstra(s);
    vector<int> T(k);
    rep(i,k) cin >> T[i], T[i]--, djikstra(T[i]);
    rep(i,1<<k) rep(j,k) dp[i][j] = 1e18;
    dp[0][0] = 0;
    rep(S,1<<k){
        rep(i,k){
            int f = T[i];
            if(bit_count(S) == 0) f = s;
            else if(!(S >> i & 1)) continue;
            rep(j,k){
                if(S >> j & 1) continue;
                chmin(dp[S | 1 << j][j], dp[S][i] + d[f][T[j]]);
            }
        }
    }
    ll res = 1e18;
    rep(i,k) chmin(res,dp[(1<<k)-1][i]);
    cout << res << endl;
}