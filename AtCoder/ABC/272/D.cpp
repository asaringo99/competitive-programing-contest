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

int n, m ;

ll d[404][404];

vector<pair<int,int>> go;

void djistra(){
    rep(i,n) rep(j,n) d[i][j] = 1e9;
    d[0][0] = 0;
    queue<tuple<int,int,int>> que;
    que.push({0,0,0});
    while(!que.empty()){
        auto[dist,x,y] = que.front(); que.pop();
        for(auto p : go){
            auto[dx,dy] = p;
            int nx = x + dx;
            int ny = y + dy;
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1;
                    que.push({d[nx][ny],nx,ny});
                }
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    for(int x = 0 ; x * x <= m ; x++){
        for(int y = 0 ; y * y <= m - x ; y++){
            if(x > n || y > n) continue;
            if(x * x + y * y == m){
                go.push_back({x,y});
                go.push_back({x,-y});
                go.push_back({-x,y});
                go.push_back({-x,-y});
            }
        }
    }
    djistra();
    rep(i,n){
        rep(j,n){
            if(d[i][j] == 1e9) cout << -1 << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}