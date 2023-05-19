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

const int dx[] = {1,0,-1,0,1,-1} , dy[] = {0,1,0,-1,1,-1} ;
int H , W ;
int sx , sy , gx , gy ;
char C[5050][5050] ;
bool use[5050][5050] ;

void bfs(int sx, int sy){
    queue<P> que ;
    que.push(P(sx,sy)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 6 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W || C[nx][ny] == '#') continue ;
            if(!use[nx][ny]){
                use[nx][ny] = true;
                que.push(P(nx,ny)) ;
            }
        }
    }
}

int n ;

int main(){
    fast_input_output
    H = 3000;
    W = 3000;
    rep(i,H) rep(j,W) C[i][j] = '#';
    cin >> n ;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        x += 1500;
        y += 1500;
        C[x][y] = '.';
    }
    rep(i,H) rep(j,W) use[i][j] = false;
    int res = 0;
    rep(i,H) rep(j,W){
        if(use[i][j]) continue;
        if(C[i][j] == '#') continue;
        bfs(i,j);
        res++;
    }
    cout << res << endl;
}