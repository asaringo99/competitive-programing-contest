#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

ll d[500][500] ;

void warshall_floyd(int k){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) rep(j,n){
        d[i][j] = INT_MAX ;
        d[i][i] = 0 ;
    }
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ;
        b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
    }
    rep(i,n) warshall_floyd(i) ;
    int k ;
    cin >> k ;
    rep(i,k){
        ll res = 0 ;
        ll x , y , z ;
        cin >> x >> y >> z ;
        x-- ;
        y-- ;
        d[x][y] = min(d[x][y],z) ;
        d[y][x] = min(d[y][x],z) ;
        warshall_floyd(x) ;
        warshall_floyd(y) ;
        rep(j,n) rrep(l,j+1,n) res += d[j][l] ;
        cout << res << endl ;
    }
}