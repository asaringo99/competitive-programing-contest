#include <bits/stdc++.h>
using namespace std ;
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

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

int H , W ;
int A[1010][1010] ;
P d[1010][1010] ;

P rec(int x , int y){
    if(d[x][y] != P(-1,-1)) return d[x][y] ;
    bool ok = true ;
    int fir = -1 , sec = -1 ;
    set<int> st ;
    rep(i,4){
        int nx = x + dx[i] , ny = y + dy[i] ;
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(A[nx][ny] > A[x][y]) continue;
        auto[a,b] = rec(nx,ny) ;
        if(a != -1) st.insert(a) ;
        if(b != -1) st.insert(b) ;
        ok = false ;
    }
    if(ok) return d[x][y] = P(x*W+y,-1) ;
    auto it = st.begin() ;
    fir = *it ;
    if(st.size() == 0) return d[x][y] = P(-1,-1) ;
    if(st.size() == 1) return d[x][y] = P(fir,-1) ;
    it++ ;
    sec = *it ;
    return d[x][y] = P(fir,sec) ;
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) d[i][j] = P(-1,-1) ;
    int res = 0 ;
    rep(i,H) rep(j,W) {
        auto[a,b] = rec(i,j) ;
        if(a != -1 && b != -1) res++ ;
    }
    cout << res << endl ;
}