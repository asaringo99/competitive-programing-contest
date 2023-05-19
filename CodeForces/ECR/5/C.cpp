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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
int H , W;

char C[1010][1010];
int res[1010][1010];
int id[1010][1010];
int d[1010][1010];
int give[101010];
bool used[1010][1010];

void bfs(int sx, int sy, int o){
    id[sx][sy] = o;
    queue<pair<int,int>> que;
    que.push({sx,sy});
    d[sx][sy] = 1;
    give[o] = 1;
    while(!que.empty()){
        auto[x,y] = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 > nx || nx >= H || 0 > ny || ny >= W || C[nx][ny] == '*') continue;
            if(id[nx][ny] != -1) continue;
            id[nx][ny] = o;
            give[o]++;
            que.push({nx,ny});
        }
    }
}

void bfs2(int sx, int sy){
    queue<pair<int,int>> que;
    que.push({sx,sy});
    used[sx][sy] = true;
    vector<pair<int,int>> vec;
    while(!que.empty()){
        auto[x,y] = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(used[nx][ny]) continue;
            used[nx][ny] = true;
            if(C[nx][ny] == '*'){
                // cout << x << " " << y << " " << give[id[x][y]] << endl;
                vec.push_back({nx,ny});
                res[nx][ny] += give[id[x][y]];
                // cout << res[nx][ny] << endl;
                continue;
            }
            que.push({nx,ny});
        }
    }
    for(auto[x,y] : vec){
        used[x][y] = false;
    }
}

void solve(){
    cin >> H >> W;
    rep(i,H) rep(j,W) cin >> C[i][j];
    rep(i,H) rep(j,W) id[i][j] = -1;
    int o = 0;
    rep(i,H) rep(j,W) if(C[i][j] == '.' && id[i][j] == -1) {
        bfs(i,j,o++);
        bfs2(i,j);
    }
    rep(i,H){
        rep(j,W){
            if(C[i][j] == '.') cout << ".";
            else cout << (res[i][j] + 1) % 10;
        }
        cout << endl;
    }
}

int main(){
    fast_io
    solve();
}