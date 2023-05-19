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

int n , m , k ;
int R[20] ;
ll d[30][10101] ;
vector<edge> G[10101] ;
unordered_map<int,int> encr , decr ;
unordered_map<int,ll> dp[1<<13][13] ;
unordered_map<int,bool> visited[1<<13][13] ;
TP E[20202] ;

void djikstra(int s){
    rep(i,n) d[s][i] = 1e16 ;
    d[s][decr[s]] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,decr[s])) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[s][v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[s][e.to] > d[s][v] + e.cost){
                d[s][e.to] = d[s][v] + e.cost ;
                que.push(P(d[s][e.to],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k ;
    rep(i,k) cin >> R[i] , R[i]-- ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
        E[i] = {a,b,c} ;
    }
    int id = 0 ;
    rep(i,k){
        int r = R[i] ;
        TP p = E[r] ;
        ll a , b , c ;
        tie(a,b,c) = p ;
        encr[a] = id ; decr[id] = a ;
        djikstra(id) ; id++ ;
        encr[b] = id ; decr[id] = b ;
        djikstra(id) ; id++ ;
    }
    rep(i,k){
        int r = R[i] ;
        TP p = E[r] ;
        ll a , b , c ;
        tie(a,b,c) = p ;
        dp[1 << i][i][a] = d[encr[b]][0] + c ;
        dp[1 << i][i][b] = d[encr[a]][0] + c ;
        visited[1 << i][i][a] = true ;
        visited[1 << i][i][b] = true ;
    }
    rep(S,1<<k){
        rep(i,k){
            if(!(S >> i & 1)) continue ;
            rep(j,k){
                if(S >> j & 1) continue ;
                int r = R[j] ;
                TP p = E[r] ;
                ll a , b , c ;
                tie(a,b,c) = p ;
                for(auto it : dp[S][i]){
                    ll node = it.first , val = it.second ;
                    if(!visited[S | 1 << j][j][a]){
                        dp[S | 1 << j][j][a] = val + d[encr[node]][b] + c ;
                        visited[S | 1 << j][j][a] = true ;
                    }
                    if(!visited[S | 1 << j][j][b]){
                        dp[S | 1 << j][j][b] = val + d[encr[node]][a] + c ;
                        visited[S | 1 << j][j][b] = true ;
                    }
                }
                for(auto it : dp[S][i]){
                    ll node = it.first , val = it.second ;
                    if(dp[S | 1 << j][j][a] > val + d[encr[node]][b] + c){
                        dp[S | 1 << j][j][a] = val + d[encr[node]][b] + c ;
                    }
                    if(dp[S | 1 << j][j][b] > val + d[encr[node]][a] + c){
                        dp[S | 1 << j][j][b] = val + d[encr[node]][a] + c ;
                    }
                }
            }
        }
    }
    ll res = 1e16 ;
    rep(i,k){
        for(auto it : dp[(1<<k)-1][i]){
            ll node = it.first , val = it.second ;
            if(visited[(1<<k)-1][i][node]) chmin(res,val+d[encr[node]][n-1]) ;
        }
    }
    cout << res << endl ;
}