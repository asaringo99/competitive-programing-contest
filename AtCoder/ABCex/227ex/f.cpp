#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int dx[] = {1,0} , dy[] = {0,1} ;

int H , W , k ;
ll A[50][50] , B[50][50] , dp[50][50][101] ;

ll f(ll x){
    rep(i,H) rep(j,W) B[i][j] = A[i][j] - x ;
    rep(i,H) rep(j,W) rep(a,60) dp[i][j][a] = 1e14 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    if(B[0][0] >= 0) {
        dp[0][0][1] = B[0][0] ;
        que.push({B[0][0],1,0,0}) ;
    }
    else {
        dp[0][0][0] = 0 ;
        que.push({0,0,0,0}) ;
    }
    while(!que.empty()){
        auto [dist,cnt,x,y] = que.top() ; que.pop() ;
        if(dist > dp[x][y][cnt]) continue ;
        for(int i = 0 ; i < 2 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx >= H || ny >= W) continue ;
            if(B[nx][ny] >= 0 && dp[nx][ny][cnt+1] > dp[x][y][cnt] + B[nx][ny]){
                dp[nx][ny][cnt+1] = dp[x][y][cnt] + B[nx][ny] ;
                que.push({dp[nx][ny][cnt+1],cnt+1,nx,ny}) ;
            }
            if(B[nx][ny] < 0 && dp[nx][ny][cnt] > dp[x][y][cnt]){
                dp[nx][ny][cnt] = dp[x][y][cnt] ;
                que.push({dp[nx][ny][cnt],cnt,nx,ny}) ;
            }
        }
    }
    ll res = 1e18 ;
    rrep(i,k,H+W) res = min(res,dp[H-1][W-1][i] + k * x) ;
    return res ;
}

int main(){
    cin >> H >> W >> k ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    ll lef = 0 , rig = 1e15 ;
    int count = 0 ;
    while(count < 100){
        ll ml = (2LL * lef + rig) / 3 , mr = (lef + 2LL * rig) / 3 ;
        if(f(ml) > f(mr)) lef = ml ;
        else rig = mr ;
        count++ ;
    }
    ll res = 1e18 ;
    rrep(i,lef,rig+1) res = min(res,f(i)) ;
    cout << res << endl ;
}