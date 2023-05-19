#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;

int n , H , W ;
char S[550][550] ;
int d[550][550] ;

void dijkstra(){
    rep(i,H) rep(j,W) d[i][j] = 1e6 ;
    d[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push(TP(0,0,0)) ;
    while(!que.empty()){
        int dist , x , y ;
        tie(dist,x,y) = que.top() ; que.pop() ;
        if(dist > d[x][y]) continue ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue ;
            if(S[nx][ny] == '.' && d[nx][ny] > d[x][y]){
                d[nx][ny] = d[x][y] ;
                que.push({dist,nx,ny}) ;
            }
            if(S[nx][ny] == '#'){
                rrep(px,-1,2) rrep(py,-1,2){
                    int mx = nx + px , my = ny + py ;
                    if(0 > mx || mx >= H || 0 > my || my >= W) continue ;
                    if(d[mx][my] > d[x][y] + 1){
                        d[mx][my] = d[x][y] + 1 ;
                        que.push({dist+1,mx,my}) ;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    dijkstra() ;
    cout << d[H-1][W-1] << endl ;
}