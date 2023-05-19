#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
bool used[1010][1010] ;
char C[1010][1010] ;
map<int,int> res ;

void bfs(int s , int t){
    int count = 0 ;
    used[s][t] = true ;
    queue<P> que ;
    que.push(P(s,t)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        count++ ;
        rrep(dx,-1,2) rrep(dy,-1,2){
            int nx = x + dx , ny = y + dy ;
            if(used[nx][ny]) continue ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W || C[nx][ny] == '.') continue ;
            used[nx][ny] = true ;
            que.push(P(nx,ny)) ;
        }
    }
    if(count % 12 == 0){
        rep(i,10000) if(count / 12 == i * i) res['A']++ ;
    }
    if(count % 16 == 0){
        rep(i,10000) if(count / 16 == i * i) res['B']++ ;
    }
    if(count % 11 == 0){
        rep(i,10000) if(count / 11 == i * i) res['C']++ ;
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    rep(i,H) rep(j,W){
        if(C[i][j] == 'o' && !used[i][j]) bfs(i,j) ;
    }
    cout << res['A'] << " " << res['B'] << " " << res['C'] << endl ;
}