#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int h , w ;
ll C[101][101] ;

int main(){
    cin >> h >> w ;
    rep(i,h) rep(j,w) cin >> C[i][j] ;
    bool ok = true ;
    rep(a,h) rrep(b,a+1,h) rep(c,w) rrep(d,c+1,w){
        if(C[a][c] + C[b][d] > C[b][c] + C[a][d]) ok = false ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}