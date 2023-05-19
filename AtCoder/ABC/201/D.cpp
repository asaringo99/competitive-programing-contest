#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int H , W ;
char A[2005][2005] ;

int main(){
    cin >> H >> W ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++) cin >> A[i][j] ;
    }
    ll dp[H][W] ;
    for(int i = 0 ; i < H ; i++) fill(dp[i],dp[i]+W,-INT_MAX) ;
    dp[H-1][W-1] = 0 ;
    for(int i = H - 1 ; i >= 0 ; i--){
        for(int j = W - 1 ; j >= 0 ; j--){
            if(i != H - 1){
                int pls = A[i+1][j] == '+' ? 1 : -1 ;
                dp[i][j] = max(dp[i][j] , pls - dp[i+1][j]) ;
            }
            if(j != W - 1){
                int pls = A[i][j+1] == '+' ? 1 : -1 ;
                dp[i][j] = max(dp[i][j] , pls - dp[i][j+1]) ;
            }
        }
    }
    if(dp[0][0] > 0) cout << "Takahashi" << endl ;
    if(dp[0][0] < 0) cout << "Aoki" << endl ;
    if(dp[0][0] == 0) cout << "Draw" << endl ;
    
}