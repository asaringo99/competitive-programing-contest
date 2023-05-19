#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define endl "\n"

const int dx[] = {1,0,-1,0} , dy[] = {0,1,0,-1} ;
int H , W ;
int sx , sy , gx , gy ;
vector<vector<char>> C, d ;

bool bfs(){
    bool ok = false;
    d.resize(H,vector<char>(W,'.'));
    queue<tuple<char,int,int>> que ;
    if(sx > 0 && C[sx-1][sy] != '#') d[sx-1][sy] = 'a', que.push({'a', sx-1, sy});
    if(sy > 0 && C[sx][sy-1] != '#') d[sx][sy-1] = 'b', que.push({'b', sx, sy-1});
    if(sx < H - 1 && C[sx+1][sy] != '#') d[sx+1][sy] = 'c', que.push({'c', sx+1, sy});
    if(sy < W - 1 && C[sx][sy+1] != '#') d[sx][sy+1] = 'd', que.push({'d', sx, sy+1});
    C[sx][sy] = '#';
    while(!que.empty()){
        auto p = que.front() ; que.pop() ;
        auto[c,x,y] = p;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W || C[nx][ny] == '#' || d[nx][ny] == c) continue ;
            if(d[nx][ny] != '.') ok = true;
            if(d[nx][ny] == '.') {
                d[nx][ny] = c;
                que.push({c,nx,ny});
            }
        }
    }
    return ok;
}

int n ;

int main(){
    fast_input_output
    cin >> H >> W ;
    C.resize(H,vector<char>(W));
    rep(i,H) rep(j,W) cin >> C[i][j];
    rep(i,H) rep(j,W) if(C[i][j] == 'S'){
        sx = i;
        sy = j;
    }
    if(bfs()) cout << "Yes" << endl;
    else cout << "No" << endl;
}