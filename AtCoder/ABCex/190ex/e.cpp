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

int n , m , k ;
vector<int> G[101010] ;
int C[101010] ;
int d[20][101010] ;

void djikstra(int s){
    rep(i,n) d[s][i] = 1e6 ;
    d[s][C[s]] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,C[s])) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[s][v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[s][u] > d[s][v] + 1){
                d[s][u] = d[s][v] + 1 ;
                que.push(P(d[s][u],u)) ;
            }
        }
    }
}

int dp[1 << 20][20] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    cin >> k ;
    rep(i,k) cin >> C[i] , C[i]-- ;
    rep(i,k) djikstra(i) ;
    rep(S,1<<k) rep(i,k) dp[S][i] = 1e6 ;
    rep(i,k) dp[1<<i][i] = 1 ;
    rrep(S,1,1<<k){
        rep(i,k){
            if(!(S >> i & 1)) continue ;
            rep(j,k){
                if(S >> j & 1) continue ;
                chmin(dp[S | 1 << j][j],dp[S][i] + d[i][C[j]]) ;
            }
        }
    }
    int res = 1e6 ;
    rep(i,k) chmin(res,dp[(1<<k)-1][i]) ;
    if(res == 1e6) res = -1 ;
    cout << res << endl ;
}