#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    int type ;
};

int n , m ;
vector<edge> G[10101] ;
ll dp[10101][150] ;

void djikstra(){
    rep(i,n) rep(j,201) dp[i][j] = 1e18 ;
    dp[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0}) ;
    while(!que.empty()){
        ll dist , v , cnt ;
        TP tp = que.top() ; que.pop() ;
        tie(dist,v,cnt) = tp ;
        if(dp[v][cnt] < dist) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(e.type == 1 && cnt < 149){
                if(dp[e.to][cnt+1] > dp[v][cnt] + cnt + 1){
                    dp[e.to][cnt+1] = dp[v][cnt] + cnt + 1 ;
                    que.push({dp[e.to][cnt+1],e.to,cnt+1}) ;
                }
            }
            if(e.type == 1 && cnt >= 149){
                if(dp[e.to][149] > dp[v][149] + cnt + 1){
                    dp[e.to][149] = dp[v][149] + cnt + 1 ;
                    que.push({dp[e.to][149],e.to,cnt+1}) ;
                }
            }
            if(e.type == 0){
                if(dp[e.to][min(149LL,cnt)] > dp[v][min(149LL,cnt)] + 1){
                    dp[e.to][min(149LL,cnt)] = dp[v][min(149LL,cnt)] + 1 ;
                    que.push({dp[e.to][min(149LL,cnt)],e.to,cnt}) ;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int c , a , b ;
        cin >> c >> a >> b ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    djikstra() ;
    rep(i,n){
        ll res = 1e18 ;
        rep(j,150) chmin(res,dp[i][j]) ;
        cout << res << endl ;
    }
}