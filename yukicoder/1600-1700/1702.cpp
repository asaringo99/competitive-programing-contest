#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
string S ;
ll dp[101010][10][2] ;

// 0123456789
//  yukicoder

int main(){
    cin >> n >> S ;
    dp[0][0][0] = 1 ;
    rep(i,n){
        rep(j,10) rep(k,2) (dp[i+1][j][k] += dp[i][j][k]) %= mod ;
        if(S[i] == '?'){
            for(int j = 8 ; j >= 0 ; j--){
                (dp[i+1][j+1][1] += dp[i][j][0]) %= mod ;
            }
        }
        if(S[i] == 'y'){
            (dp[i+1][1][0] += dp[i][0][0]) %= mod ;
            (dp[i+1][1][1] += dp[i][0][1]) %= mod ;
        }
        if(S[i] == 'u'){
            (dp[i+1][2][0] += dp[i][1][0]) %= mod ;
            (dp[i+1][2][1] += dp[i][1][1]) %= mod ;
        }
        if(S[i] == 'k'){
            (dp[i+1][3][0] += dp[i][2][0]) %= mod ;
            (dp[i+1][3][1] += dp[i][2][1]) %= mod ;
        }
        if(S[i] == 'i'){
            (dp[i+1][4][0] += dp[i][3][0]) %= mod ;
            (dp[i+1][4][1] += dp[i][3][1]) %= mod ;
        }
        if(S[i] == 'c'){
            (dp[i+1][5][0] += dp[i][4][0]) %= mod ;
            (dp[i+1][5][1] += dp[i][4][1]) %= mod ;
        }
        if(S[i] == 'o'){
            (dp[i+1][6][0] += dp[i][5][0]) %= mod ;
            (dp[i+1][6][1] += dp[i][5][1]) %= mod ;
        }
        if(S[i] == 'd'){
            (dp[i+1][7][0] += dp[i][6][0]) %= mod ;
            (dp[i+1][7][1] += dp[i][6][1]) %= mod ;
        }
        if(S[i] == 'e'){
            (dp[i+1][8][0] += dp[i][7][0]) %= mod ;
            (dp[i+1][8][1] += dp[i][7][1]) %= mod ;
        }
        if(S[i] == 'r'){
            (dp[i+1][9][0] += dp[i][8][0]) %= mod ;
            (dp[i+1][9][1] += dp[i][8][1]) %= mod ;
        }
    }
    cout << (dp[n][9][0] + dp[n][9][1]) % mod << endl ;
}