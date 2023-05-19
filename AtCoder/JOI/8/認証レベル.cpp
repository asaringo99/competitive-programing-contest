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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

const int dx[] = {0,0,1,-1} , dy[] = {1,-1,0,0} ;

int R , HS , WS , xs , ys , HT , WT , xt , yt ;

vector<vector<ll>> S ;
vector<vector<ll>> T ;

void djikstra(int sx , int sy , vector<vector<ll>> D , int H , int W ,unordered_map<int,ll> &mp){
    vector<vector<ll>> d ;
    d.resize(H,vector<ll>(W,1e16)) ;
    d[sx][sy] = D[sx][sy] ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({d[sx][sy],sx,sy}) ;
    int cnt = 0 ;
    while(!que.empty()){
        auto[dist,x,y] = que.top() ; que.pop() ;
        if(dist > d[x][y]) continue;
        cnt++ ;
        mp[cnt] = dist ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            ll cost = max(dist,D[nx][ny]) ;
            if(d[nx][ny] > cost){
                d[nx][ny] = cost ;
                que.push({cost,nx,ny}) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> R ;
    cin >> WS >> HS >> ys >> xs ; ys-- ; xs-- ;
    S.resize(HS,vector<ll>(WS)) ;
    rep(i,HS) rep(j,WS) cin >> S[i][j] ;
    cin >> WT >> HT >> yt >> xt ; yt-- ; xt-- ;
    T.resize(HT,vector<ll>(WT)) ;
    rep(i,HT) rep(j,WT) cin >> T[i][j] ;
    unordered_map<int,ll> mp_s , mp_t ;
    djikstra(xs,ys,S,HS,WS,mp_s) ;
    djikstra(xt,yt,T,HT,WT,mp_t) ;
    ll res = 1e18 ;
    rep(i,R+1){
        if(R-i>HT*WT) continue;
        if(i>HS*WS) continue;
        chmin(res,mp_s[i]+mp_t[R-i]) ;
    }
    cout << res << endl ;
}