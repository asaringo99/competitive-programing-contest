#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

string K ;
int D ;

ll dp[10007][2][105] ;

int main(){
    cin >> K >> D ;
    int n = K.size() ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0][0] = 1 ;
    vector<int> digit ;
    rep(i,n) digit.push_back(K[i] - '0') ;
    for(int i = 0 ; i < n ; i++){
        for(int smaller = 0 ; smaller < 2 ; smaller++){
            for(int j = 0 ; j < D ; j++){
                for(int x = 0 ; x <= (smaller ? 9 : digit[i]) ; x++){
                    int div = (j + x) % D ;
                    (dp[i+1][ smaller || x < digit[i] ][div] += dp[i][smaller][j]) %= mod ;
                }
            }
        }
    }
    // 00000000 というのもカウントされているので-1する
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl ;
}