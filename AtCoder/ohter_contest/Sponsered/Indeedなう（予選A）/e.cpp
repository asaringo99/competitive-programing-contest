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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int H, W;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

map<vector<vector<int>>,int> mp1, mp2;

void rec(int px, int py, int x, int y, int cnt, map<vector<vector<int>>,int> &mp, vector<vector<int>> C){
    if(!mp.count(C)) mp[C] = 25;
    chmin(mp[C], cnt);
    if(cnt == 12) return;
    rep(i,4){
        int nx = x + dx[i], ny = y + dy[i];
        if(px == nx && py == ny) continue;
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        auto D = C;
        swap(D[x][y],D[nx][ny]);
        rec(x, y, nx, ny, cnt + 1, mp, D);
    }
}

void solve(){
    cin >> H >> W;
    vector<vector<int>> C(H, vector<int>(W));
    vector<vector<int>> S(H, vector<int>(W));
    rep(i,H) rep(j,W) S[i][j] = i * W + j;
    vector<int> A(H*W);
    rep(i,H) rep(j,W) cin >> C[i][j], C[i][j]--;
    int sx, sy;
    rep(i,H) rep(j,W){
        int a = C[i][j];
        A[i*W+j] = a;
        if(a == -1) sx = i, sy = j;
        if(a == -1) A[i*W+j] = H*W-1, C[i][j] = H*W-1;
    }
    rec(-1,-1,sx,sy,0,mp1,C);
    rec(-1,-1,H-1,W-1,0,mp2,S);
    int res = 25;
    for(auto[vec,cnt] : mp1){
        if(!mp2.count(vec)) continue;
        chmin(res,cnt+mp2[vec]);
    }
    cout << res << endl;
}

int main(){
    // fast_io
    solve();
}