#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
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

int H , W , n ;
int X[10101] , Y[10101] , Z[10101] ;
int d[3030][3030] ;

void djikstra(){
    priority_queue<TP> que ;
    rep(i,n){
        int x = X[i] , y = Y[i] , h = Z[i] ;
        d[x][y] = h ;
        que.push({h,x,y}) ;
    }
    while(!que.empty()){
        auto[dist,x,y] = que.top() ; que.pop() ;
        if(d[x][y] > dist) continue;
        rrep(dx,-1,2) rrep(dy,-1,2){
            int nx = x + dx , ny = y + dy ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(d[nx][ny] < d[x][y] - 1){
                d[nx][ny] = d[x][y] - 1 ;
                que.push({d[nx][ny],nx,ny}) ;
            }
        }
    }
}

int main(){
    cin >> W >> H >> n ;
    rep(i,n) cin >> Y[i] >> X[i] >> Z[i] ;
    djikstra() ;
    ll res = 0;
    rep(i,H) rep(j,W) res += d[i][j] ;
    rep(i,H){
        rep(j,W) cout << d[i][j] << " " ; cout << endl ;
    }
    cout << res << endl ;
}