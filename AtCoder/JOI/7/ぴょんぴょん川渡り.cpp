#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll d[202][20][101] ;

vector<P> G[202] ;
ll C[202][20] ;

void djikstra(){
    rep(i,n) rep(j,20) rep(k,101)  d[i][j][k] = 1e16 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    rep(i,G[0].size()) {
        d[0][i][0] = 0 ;
        que.push({0,0,i,0}) ;
    }
    if(m > 0) rep(i,G[1].size()) {
        d[1][i][1] = 0 ;
        que.push({0,1,i,1}) ;
    }
    while(!que.empty()){
        auto [dist,row,col,cnt] = que.top() ; que.pop() ;
        if(d[row][col][cnt] < dist) continue;
        auto [v,slip] = G[row][col] ;
        ll x = C[row][col] ;
        for(int i = 0 ; i < G[row+1].size() ; i++){
            auto [nv,s] = G[row+1][i] ;
            ll nx = C[row+1][i] ;
            if(d[row+1][nv][cnt] > d[row][col][cnt] + (slip + s) * abs(nx - x)){
                d[row+1][nv][cnt] = d[row][col][cnt] + (slip + s) * abs(nx - x) ;
                que.push({d[row+1][nv][cnt],row+1,nv,cnt}) ;
            }
        }
        if(cnt >= m) continue;
        for(int i = 0 ; i < G[row+2].size() ; i++){
            auto [nv,s] = G[row+2][i] ;
            ll nx = C[row+2][i] ;
            if(d[row+2][nv][cnt+1] > d[row][col][cnt] + (slip + s) * abs(nx - x)){
                d[row+2][nv][cnt+1] = d[row][col][cnt] + (slip + s) * abs(nx - x) ;
                que.push({d[row+2][nv][cnt+1],row+2,nv,cnt+1}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n){
        int c ;
        cin >> c;
        rep(j,c){
            int x , y ;
            cin >> x >> y ;
            G[i].push_back(P(j,y)) ;
            C[i][j] = x ;
        }
    }
    djikstra() ;
    ll res = 1e16 ;
    rep(i,20) rep(j,m+1) chmin(res,d[n-1][i][j]) ;
    rep(i,20) rep(j,m) chmin(res,d[n-2][i][j]) ;
    cout << res << endl ;
}