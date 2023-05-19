#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

int H , W , X , Y ;
ll A[505][505] ;
bool used[505][505] ;

bool bfs(){
    ll level = A[X][Y] ;
    used[X][Y] = true ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    if(X+1< H) {
        used[X+1][Y] = true ;
        que.push({A[X+1][Y],X+1,Y}) ;
    }
    if(X-1>=0) {
        used[X-1][Y] = true ;
        que.push({A[X-1][Y],X-1,Y}) ;
    }
    if(Y+1< W) {
        used[X][Y+1] = true ;
        que.push({A[X][Y+1],X,Y+1}) ;
    }
    if(Y-1>=0) {
        used[X][Y-1] = true ;
        que.push({A[X][Y-1],X,Y-1}) ;
    }
    while(!que.empty()){
        auto [d,x,y] = que.top() ; que.pop() ;
        if(d >= level) return false ;
        level += A[x][y] ;
        if(x+1<H && !used[x+1][y]) {
            used[x+1][y] = true ;
            que.push({A[x+1][y],x+1,y}) ;
        }
        if(y+1<W && !used[x][y+1]) {
            used[x][y+1] = true ;
            que.push({A[x][y+1],x,y+1}) ;
        }
        if(x-1>=0 && !used[x-1][y]) {
            used[x-1][y] = true ;
            que.push({A[x-1][y],x-1,y}) ;
        }
        if(y-1>=0 && !used[x][y-1]) {
            used[x][y-1] = true ;
            que.push({A[x][y-1],x,y-1}) ;
        }
    }
    return true ;
}

int main(){
    fast_input_output
    cin >> H >> W >> X >> Y ;
    X-- ; Y-- ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    if(bfs()) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}