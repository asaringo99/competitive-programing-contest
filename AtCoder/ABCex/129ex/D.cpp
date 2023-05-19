#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W ;
char S[2005][2005] ;

int yoko[2005][2005] ;
int tate[2005][2005] ;
bool used_yoko[2005][2005] ;
bool used_tate[2005][2005] ;

int fy(int x , int y , int count){
    if(y == W || S[x][y] == '#') return count ;
    used_yoko[x][y] = true ;
    return yoko[x][y] = fy(x,y+1,count+1) ;
}

int fx(int x , int y , int count){
    if(x == H || S[x][y] == '#') return count ;
    used_tate[x][y] = true ;
    return tate[x][y] = fx(x+1,y,count+1) ;
}

int main(){
    cin >> H >> W ;
    memset(used_tate,0,sizeof(used_tate)) ;
    memset(used_yoko,0,sizeof(used_yoko)) ;
    for(int i = 0 ; i < H ; i++) for(int j = 0 ; j < W ; j++) cin  >> S[i][j] ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if(S[i][j] == '.' && !used_tate[i][j]) fx(i,j,0) ;
            if(S[i][j] == '.' && !used_yoko[i][j]) fy(i,j,0) ;
        }
    }
    int res = 0 ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            res = max(res,tate[i][j] + yoko[i][j] - 1) ;
        }
    }
    cout << res << endl ;
}