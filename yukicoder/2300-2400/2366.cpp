#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
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
#define v1(n,a) vector<ll>(n,a)
#define v2(n,m,a) vector<vector<ll>>(n,v1(m,a))
#define v3(n,m,k,a) vector<vector<vector<ll>>>(n,v2(m,k,a))
#define v4(n,m,k,l,a) vector<vector<vector<vector<ll>>>>(n,v3(m,k,l,a))
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}

vector<ll> A, B, C, D;

int H, W, k, T;
ll d[101][101][404];
pair<ll,ll> magic[101][101];
bool isok[101][101];

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void bfs(){
    rep(i,H) rep(j,W) rep(t,404) d[i][j][t] = 1e18;
    d[0][0][200+T] = 0;
    using tp = tuple<ll,int,int,int>;
    priority_queue<tp,vector<tp>,greater<tp>> que;
    que.push({0,0,0,200+T});
    while(!que.empty()){
        auto[dist,x,y,t] = que.top(); que.pop();
        if(dist > d[x][y][t]) continue;
        rep(i,4){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(t == 0) continue;
            if(d[nx][ny][t-1] > d[x][y][t]){
                d[nx][ny][t-1] = d[x][y][t];
                que.push({d[nx][ny][t-1],nx,ny,t-1});
            }
        }
        if(!isok[x][y]) continue;
        auto[c,val] = magic[x][y];
        int nt = t - 1 + c >= 200 + H + W ? 200 + H + W : t - 1 + c;
        if(d[x][y][nt] > d[x][y][t] + val){
            d[x][y][nt] = d[x][y][t] + val;
            que.push({d[x][y][nt],x,y,nt});
        }
    }
}

void solve(){
    cin >> H >> W >> k >> T;
    A = vector<ll>(k);
    B = vector<ll>(k);
    C = vector<ll>(k);
    D = vector<ll>(k);
    rep(i,k) cin >> A[i] >> B[i] >> C[i] >> D[i];
    rep(i,k) A[i]--;
    rep(i,k) B[i]--;
    rep(i,k){
        magic[A[i]][B[i]] = {C[i],D[i]};
        isok[A[i]][B[i]] = true;
    }
    bfs();
    ll res = 1e18;
    rrep(i,200,403) chmin(res,d[H-1][W-1][i]);
    if(res == 1e18) res = -1;
    cout << res << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}