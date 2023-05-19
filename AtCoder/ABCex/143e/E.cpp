#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m , l , q ;
ll d[303][303] ;

void f(){
    rep(k,n) rep(i,n) rep(j,n) chmin(d[i][j],d[i][k]+d[k][j]) ;
}

int main(){
    cin >> n >> m >> l ;
    rep(i,n) rep(j,n) if(i != j) d[i][j] = 1e16 ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
    }
    f() ;
    rep(i,n) rep(j,n) {
        if(d[i][j] <= l) d[i][j] = 1 ;
        else d[i][j] = 1e16 ;
    }
    f() ;
    cin >> q ;
    rep(i,q){
        int s , t ;
        cin >> s >> t ;
        s-- ; t-- ;
        ll res = d[s][t] == 1e16 ? 0 : d[s][t] ;
        cout << res - 1 << endl ;
    }
}