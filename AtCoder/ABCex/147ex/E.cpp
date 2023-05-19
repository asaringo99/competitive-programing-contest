#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
bool dp[100][100][13000] ;
int A[100][100] , B[100][100] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) cin >> B[i][j] ;
    dp[0][0][abs(A[0][0]-B[0][0])] = 1 ;
    rep(i,H) rep(j,W) rep(k,13000){
        if(!dp[i][j][k]) continue ;
        int val1 = abs(A[i+1][j] - B[i+1][j]) ;
        int val2 = abs(A[i][j+1] - B[i][j+1]) ;
        if(i + 1 < H){
            dp[i+1][j][abs(k+val1)] = 1 ;
            dp[i+1][j][abs(k-val1)] = 1 ;
        }
        if(j + 1 < W){
            dp[i][j+1][abs(k+val2)] = 1 ;
            dp[i][j+1][abs(k-val2)] = 1 ;
        }
    }
    for(int i = 0 ; i < 13000 ; i++) if(dp[H-1][W-1][i]){
        cout << i << endl ;
        return 0 ;
    }
}