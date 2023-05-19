#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
char C[20][20] ;
int dx[4] = {1,1,0,-1} , dy[4] = {0,1,1,-1} ;

int dir(int x , int y , int dep , char z , int d){
    int nx = x + dx[d] , ny = y + dy[d] ;
    if(dep >= 5) return dep ;
    if(0 > nx || nx >= 19) return dep ;
    if(0 > ny || ny >= 19) return dep ;
    if(C[nx][ny] != z) return dep ;
    return dir(nx,ny,dep+1,z,d) ;
}


int main(){
    int w = 0 , b = 0 ;
    rep(i,19) rep(j,19){
        char c ;
        cin >> c ;
        C[i][j] = c ;
        if(c == 'x') b++ ;
        if(c == 'o') w++ ;
    }
    if(abs(b - w) > 1){
        cout << "NO" << endl ;
        return 0 ;
    }
    rep(i,19) rep(j,19){
        int res = -1 ;
        if(C[i][j] != '.') rep(i,4) res = max(res,dir(i,j,0,C[i][j],i)) ;
        if(res >= 5){
            cout << "NO" << endl ;
            return 0 ;
        }
    }
    cout << "YES" << endl ;
}