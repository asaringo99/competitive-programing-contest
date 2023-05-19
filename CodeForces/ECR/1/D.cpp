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

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int n, m;
vector<vector<char>> C;
vector<vector<int>> I;
vector<vector<bool>> D;
int res[1010101];

int bfs(int sx, int sy, int id){
    if(I[sx][sy] != -1) return I[sx][sy];
    I[sx][sy] = id;
    queue<pair<int,int>> que;
    que.push({sx, sy});
    int sum = 0;
    while(!que.empty()){
        auto[x, y] = que.front(); que.pop();
        if(D[x][y]) continue;
        I[x][y] = id;
        if(x > 0) if(C[x-1][y] == '*') sum++;
        if(y > 0) if(C[x][y-1] == '*') sum++;
        if(x < n - 1) if(C[x+1][y] == '*') sum++;
        if(y < m - 1) if(C[x][y+1] == '*') sum++;
        D[x][y] = true;
        rep(i,4){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m || C[nx][ny] == '*' || I[nx][ny] == id) continue;
            que.push({nx,ny});
            I[nx][ny] = id;
        }
    }
    res[id] = sum;
    return id;
}

void solve(){
    int q;
    cin >> n >> m >> q;
    C = vector<vector<char>>(n, vector<char>(m));
    I = vector<vector<int>>(n, vector(m, -1));
    D = vector<vector<bool>>(n, vector(m, false));
    rep(i,n) rep(j,m) cin >> C[i][j];
    int id = 0;
    rep(i,q){
        int sx, sy;
        cin >> sx >> sy;
        sx--; sy--;
        int v = bfs(sx, sy, id);
        cout << res[v] << endl;
        id++;
    }
}

int main(){
    fast_io
    solve();
}