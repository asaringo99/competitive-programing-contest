#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

int H , W;
char S[2020][2020] ;
int d[2020][2020] ;
bool used[2020][2020] ;
vector<P> mp[26] ;
int sx , sy , gx , gy ;

void djikstra(){
    rep(i,H) rep(j,W) d[i][j] = 1e8 ;
    d[sx][sy] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,sx,sy}) ;
    while(!que.empty()){
        auto [dist,x,y] = que.top() ; que.pop() ;
        if(dist > d[x][y]) continue;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#') continue;
            if(d[nx][ny] > d[x][y] + 1){
                d[nx][ny] = d[x][y] + 1 ;
                que.push({d[nx][ny],nx,ny}) ;
            }
        }
        if(!used[x][y] && S[x][y] != '.' && S[x][y] != '#' && S[x][y] != 'S' && S[x][y] != 'G'){
            used[x][y] = true ;
            for(P p : mp[S[x][y]-'a']){
                auto [nx,ny] = p ;
                if(d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1 ;
                    que.push({d[nx][ny],nx,ny}) ;
                }
                used[nx][ny] = true ;
            }
        }
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) {
        cin >> S[i][j] ;
        if(S[i][j] != '.' && S[i][j] != '#' && S[i][j] != 'S' && S[i][j] != 'G'){
            mp[S[i][j]-'a'].push_back(P(i,j)) ;
        }
        if(S[i][j] == 'S') sx = i , sy = j ;
        if(S[i][j] == 'G') gx = i , gy = j ;
    }
    djikstra() ;
    ll res = d[gx][gy] ;
    if(res == 1e8) res = -1 ;
    cout << res << endl ;
}