#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int dx[4] = {-1,1,0,0} , dy[4] = {0,0,1,-1} ;
ll cost[4] ;

int H , W ;
ll u , d , r , l , k , p ;
int xs , ys , xg , yg ;

char S[110][110] ;
ll dist[110][110] ;

void bfs(){
    rep(i,H) rep(j,W) dist[i][j] = 1e17 ;
    dist[xs][ys] = 0 ;
    queue<P> que ;
    que.push(P(xs,ys)) ;
    while(!que.empty()){
        P pr = que.front() ; que.pop() ;
        int x = pr.first , y = pr.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W || S[nx][ny] == '#') continue ;
            if(S[nx][ny] == '@' && dist[nx][ny] > dist[x][y] + p + cost[i]){
                dist[nx][ny] = dist[x][y] + p + cost[i] ;
                que.push(P(nx,ny)) ;
                continue ;
            }
            if(S[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + cost[i]){
                dist[nx][ny] = dist[x][y] + cost[i] ;
                que.push(P(nx,ny)) ;
                continue ;
            }
        }
    }
}

int main(){
    cin >> H >> W >> u >> d >> r >> l >> k >> p >> xs >> ys >> xg >> yg ;
    cost[0] = u ;
    cost[1] = d ;
    cost[2] = r ;
    cost[3] = l ;
    xs-- ; ys-- ; xg-- ; yg-- ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    bfs() ;
    if(dist[xg][yg] > k) cout << "No" << endl ;
    else cout << "Yes" << endl ;
}