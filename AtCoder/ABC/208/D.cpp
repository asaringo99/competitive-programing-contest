#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

ll d[500][500] ;

void warshall_floyd(int k){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) fill(d[i],d[i]+n,INT_MAX) ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ;
        b-- ;
        d[a][b] = c ;
    }
    ll res = 0 ;
    for(int k = 0 ; k < n ; k++){
        warshall_floyd(k) ;
        rep(i,n) rep(j,n) {
            if(d[i][j] == INT_MAX || i == j) continue ;
            res += d[i][j] ;
        }
    }
    cout << res << endl ;
}