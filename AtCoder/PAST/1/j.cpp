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
using tpl = tuple<ll,int,int>;

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int H, W;
ll A[60][60];
ll d[60][60][60][60];

int n , m ;

ll djikstra(int sx, int sy){
    rep(i,H) rep(j,W) d[sx][sy][i][j] = 1e16 ;
    d[sx][sy][sx][sy] = 0;
    priority_queue<tpl,vector<tpl>,greater<tpl>> que ;
    que.push({0,sx,sy});
    while(!que.empty()){
        auto[dist, x, y] = que.top(); que.pop() ;
        if(d[sx][sy][x][y] < dist) continue;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(d[sx][sy][nx][ny] > d[sx][sy][x][y] + A[nx][ny]){
                d[sx][sy][nx][ny] = d[sx][sy][x][y] + A[nx][ny];
                que.push({d[sx][sy][nx][ny], nx, ny}) ;
            }
        }
    }
    return A[sx][sy] + d[sx][sy][H-1][0] + d[sx][sy][H-1][W-1] + d[sx][sy][0][W-1];
}


int main(){
    fast_io
    cin >> H >> W;
    rep(i,H) rep(j,W) cin >> A[i][j];
    ll res = 1e18;
    rep(i,H) rep(j,W) chmin(res,djikstra(i,j));
    cout << res << endl;
}