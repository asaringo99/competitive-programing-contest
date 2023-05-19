#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

int n , m ;
char C[550][550] ;
double d[550][550] ;

double powd(double x , ll n){
    double res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

void bfs(int s , int t , int x , int y){
    rep(i,n) rep(j,m) d[i][j] = 0 ;
    d[s][t] = 10 ;
    d[x][y] = 1e9 ;
    queue<TP> que ;
    que.push({s,t,0}) ;
    while(!que.empty()){
        TP tp = que.front() ; que.pop() ;
        int x , y , t ;
        tie(x,y,t) = tp ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= n || 0 > ny || ny >= m || C[nx][ny] == '#') continue ;
            if(C[nx][ny] == 's') continue ;
            if(C[nx][ny] == 'g'){
                d[nx][ny] = max(d[nx][ny],d[x][y]) ;
                continue ;
            }
            double val = C[nx][ny] - '0' ;
            val *= powd(0.99,t+1) ;
            val = min(val,d[x][y]) ;
            if(d[nx][ny] < val){
                d[nx][ny] = val ;
                que.push({nx,ny,t+1}) ;
            }
        }
    }
}

int main(){
    int  s , t , x , y ;
    cin >> n >> m ;
    rep(i,n) rep(j,m){
        cin >> C[i][j] ;
        if(C[i][j] == 's'){
            s = i ;
            t = j ;
        }
        if(C[i][j] == 'g'){
            x = i ;
            y = j ;
        }
    }
    bfs(s,t,x,y) ;
    if(d[x][y] == 1e9) cout << -1 << endl ;
    else cout << fixed << setprecision(10) << d[x][y] << endl ;
}