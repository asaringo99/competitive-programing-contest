#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<double,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int dx[] = {0,0,1,-1} , dy[] = {1,-1,0,0} ;

int n , m ;
char C[505][505] ;
double d[505][505] ;

void bfs(int s , int t , int p , int q){
    d[s][t] = 1e15 ;
    d[p][q] = -1 ;
    queue<TP> que ;
    que.push({1,s,t}) ;
    while(!que.empty()){
        TP tp = que.front() ; que.pop() ;
        double t ; int x , y ;
        tie(t,x,y) = tp ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            double val ;
            if(nx == p && ny == q) val = 1e18 ;
            else val = C[nx][ny] - '0' ;
            if(0 > nx || nx >= n || 0 > ny || ny >= m || C[nx][ny] == '#') continue ;
            if(d[nx][ny] < d[x][y] && d[nx][ny] < val * t * 0.99){
                d[nx][ny] = min(d[x][y],val*t*0.99) ;
                que.push({t*0.99,nx,ny}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    int sx , sy , gx , gy ;
    rep(i,n) rep(j,m) {
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
    bfs(sx,sy,gx,gy) ;
    if(d[gx][gy] == -1) cout << -1 << endl ;
    else cout << setprecision(15) << d[gx][gy] << endl ;
}