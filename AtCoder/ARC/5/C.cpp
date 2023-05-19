#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;

int h , w ;
char C[505][505] ;
int d[505][505] ;

void dijkstra(int s , int t){
    rep(i,h) rep(j,w) d[i][j] = 1e8 ;
    d[s][t] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,s,t}) ;
    while(!que.empty()){
        TP tp = que.top() ; que.pop() ;
        int dis , x , y ;
        tie(dis,x,y) = tp ;
        if(d[x][y] < dis) continue ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= h || 0 > ny || ny >= w) continue ;
            if(C[nx][ny] == '#' && d[nx][ny] > d[x][y] + 1){
                d[nx][ny] = d[x][y] + 1 ;
                que.push({d[nx][ny],nx,ny}) ;
            }
            else if(C[nx][ny] != '#' && d[nx][ny] > d[x][y]){
                d[nx][ny] = d[x][y] ;
                que.push({d[nx][ny],nx,ny}) ;
            }
        }
    }
}

int main(){
    cin >> h >> w ;
    int sx , sy , gx , gy ;
    rep(i,h) rep(j,w) {
        cin >> C[i][j] ;
        if(C[i][j] == 's'){
            sx = i ;
            sy = j ;
        }
        if(C[i][j] == 'g'){
            gx = i ;
            gy = j ;
        }
    }
    dijkstra(sx,sy) ;
    if(d[gx][gy] > 2) cout << "NO" << endl ;
    else cout << "YES" << endl ;
}