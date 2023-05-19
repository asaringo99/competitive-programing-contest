#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

const int dx[] = {1,0,-1,0,0} , dy[] = {0,1,0,-1,0} ;
int H , W ;
int sx , sy , gx , gy ;
int d[300][300][5];

void bfs(){
    rep(i,H) rep(j,W) rep(k,5) d[i][j][k] = 1e9 ;
    d[sx][sy][4] = 0 ;
    queue<tuple<int,int,int>> que ;
    que.push({sx,sy,4}) ;
    while(!que.empty()){
        auto[x,y,dir] = que.front() ; que.pop() ;
        for(int i = 0 ; i < 5 ; i++){
            if(i == dir) continue;
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue ;
            if(d[nx][ny][i] > d[x][y][dir] + 1){
                d[nx][ny][i] = d[x][y][dir] + 1 ;
                que.push({nx,ny,i}) ;
            }
        }
    }
}

void solve(){
    cin >> gx >> gy;
    gx += 100;
    gy += 100;
    int res = 1000000000;
    rep(i,5) chmin(res,d[gx][gy][i]);
    cout << res << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    H = 201;
    W = 201;
    sx = 100;
    sy = 100;
    bfs();
    rep(i,z) solve();
}