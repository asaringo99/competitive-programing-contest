#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
char C[20][20] ;
bool used[20][20] ;

int dx[] = {0,0,1,-1} , dy[] = {1,-1,0,0} ;

int dfs(int sx , int sy , int x , int y , int dep){
    if(sx == x && sy == y && used[sx][sy]) return dep ;
    int res = -1 ;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i] , ny = y + dy[i] ;
        if(0 <= nx && nx < H && 0 <= ny && ny < W && !used[nx][ny] && C[nx][ny] == '.'){
            used[nx][ny] = true ;
            res = max(res,dfs(sx,sy,nx,ny,dep+1)) ;
            used[nx][ny] = false ;
        }
    }
    return res ;
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    int res = -1 ;
    rep(i,H) rep(j,W) if(C[i][j] == '.'){
        memset(used,0,sizeof(used)) ;
        res = max(res,dfs(i,j,i,j,0)) ;
    }
    res = res < 3 ? -1 : res ;
    cout << res << endl ;
}