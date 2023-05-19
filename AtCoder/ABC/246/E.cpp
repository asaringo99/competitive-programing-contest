#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

bool done[2020][2020][4] ;
P d[2020][2020][4] ;
int dist[2020][2020][4] ;

int n , sx , sy , gx , gy ;
char S[2020][2020] ;

void dfs(){
    rep(i,n) rep(j,n) rep(k,4) dist[i][j][k] = 1e8 ;
    dist[sx][sy][0] = 0 ;
    dist[sx][sy][1] = 0 ;
    dist[sx][sy][2] = 0 ;
    dist[sx][sy][3] = 0 ;
    queue<TP> que ;
    que.push({sx,sy,0}) ;
    que.push({sx,sy,1}) ;
    que.push({sx,sy,2}) ;
    que.push({sx,sy,3}) ;
    while(!que.empty()){
        auto [x,y,dir] = que.front() ; que.pop() ;
        rep(i,4){
            if(dir == i){
                if(i == 0) if(!(x+1 >= n || y+1 >= n || S[x+1][y+1] == '#'))  if(dist[x+1][y+1][i] > dist[x][y][dir]){
                    dist[x+1][y+1][i] = dist[x][y][dir] ;
                    que.push({x+1,y+1,i}) ;
                }
                if(i == 1) if(!(x+1 >= n || y-1 < 0 || S[x+1][y-1] == '#'))  if(dist[x+1][y-1][i] > dist[x][y][dir]){
                    dist[x+1][y-1][i] = dist[x][y][dir] ;
                    que.push({x+1,y-1,i}) ;
                }
                if(i == 2) if(!(x-1 < 0 || y+1 >= n || S[x-1][y+1] == '#'))  if(dist[x-1][y+1][i] > dist[x][y][dir]){
                    dist[x-1][y+1][i] = dist[x][y][dir] ;
                    que.push({x-1,y+1,i}) ;
                }
                if(i == 3) if(!(x-1 < 0 || y-1 < 0 || S[x-1][y-1] == '#'))  if(dist[x-1][y-1][i] > dist[x][y][dir]){
                    dist[x-1][y-1][i] = dist[x][y][dir] ;
                    que.push({x-1,y-1,i}) ;
                }
            }
            else{
                if(i == 0) if(!(x+1 >= n || y+1 >= n || S[x+1][y+1] == '#')) if(dist[x+1][y+1][i] > dist[x][y][dir] + 1) {
                    dist[x+1][y+1][i] = dist[x][y][dir] + 1 ;
                    que.push({x+1,y+1,i}) ;
                }
                if(i == 1) if(!(x+1 >= n || y-1 < 0 || S[x+1][y-1] == '#'))  if(dist[x+1][y-1][i] > dist[x][y][dir] + 1){
                    dist[x+1][y-1][i] = dist[x][y][dir] + 1 ;
                    que.push({x+1,y-1,i}) ;
                }
                if(i == 2) if(!(x-1 < 0 || y+1 >= n || S[x-1][y+1] == '#'))  if(dist[x-1][y+1][i] > dist[x][y][dir] + 1){
                    dist[x-1][y+1][i] = dist[x][y][dir] + 1 ;
                    que.push({x-1,y+1,i}) ;
                }
                if(i == 3) if(!(x-1 < 0 || y-1 < 0 || S[x-1][y-1] == '#'))  if(dist[x-1][y-1][i] > dist[x][y][dir] + 1){
                    dist[x-1][y-1][i] = dist[x][y][dir] + 1 ;
                    que.push({x-1,y-1,i}) ;
                }
            }
        }
    }
}

int main(){
    cin >> n >> sx >> sy >> gx >> gy ;
    sx-- ; sy-- ; gx-- ; gy-- ;
    rep(i,n) rep(j,n) cin >> S[i][j] ;
    dfs() ;
    int res = 1e8 ;
    rep(i,4) res = min(res,dist[gx][gy][i]) ;
    if(res == 1e8) res = -1 ;
    else res++ ;
    cout << res << endl ;
}