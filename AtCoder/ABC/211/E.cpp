#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
bool used[100][100] ;
map<vector<vector<bool>>,bool> mp ;
char S[100][100] ;
ll res ;

int dx[] = {0,0,-1,1} , dy[] = {1,-1,0,0} ;

void sol(int x , int y , int dep){
    used[x][y] = true ;
    if(dep == k){
        vector<vector<bool>> spi(n,vector<bool>(n)) ;
        rep(p,n) rep(q,n) spi[p][q] = used[p][q] ;
        if(mp[spi]) return ;
        mp[spi] = true ;
        rep(i,n){
            rep(j,n) cout << used[i][j] << " " ;
            cout << endl ;
        }
        cout << endl ;
        res++ ;
        return ;
    }
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i] , ny = y + dy[i] ;
        if(0 <= nx && nx < n && 0 <= ny && ny < n && !used[nx][ny] && S[nx][ny] == '.'){
            sol(nx,ny,dep+1) ;
            used[nx][ny] = false ;
        }
    }
}

ll dfs(){
    rep(i,n) rep(j,n) {
        if(S[i][j] != '#') {
            memset(used,0,sizeof(used)) ;
            sol(i,j,1) ;
        }
    }
    return res ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) rep(j,n) cin >> S[i][j] ;
    res = 0 ;
    dfs() ;
    cout << res << endl ;
}