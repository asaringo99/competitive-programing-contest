#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int H , W ;
ll A[33][33] ;
ll d[33][33][909] ;

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

void djikstra(){
    rep(i,H) rep(j,W) rep(k,H*W+1) d[i][j][k] = 1e18 ;
    d[0][0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0,0}) ;
    while(!que.empty()){
        auto [dist,x,y,cost] = que.top() ; que.pop() ;
        if(dist > d[x][y][cost]) continue;
        rep(i,4){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            ll val = (cost * 2 + 1) * A[nx][ny] ;
            if(d[nx][ny][cost+1] > d[x][y][cost] + val){
                d[nx][ny][cost+1] = d[x][y][cost] + val ;
                que.push({d[nx][ny][cost+1],nx,ny,cost+1}) ;
            }
        }
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    djikstra() ;
    ll res = 1e18 ;
    rep(i,H*W+1) chmin(res,d[H-1][W-1][i]) ;
    cout << res << endl ;
}