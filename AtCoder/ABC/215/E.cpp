#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;

int n ;
string S ;
ll dp[1010][(1<<11) + 20][15] ;

int main(){
    cin >> n >> S ;
    dp[0][1 << (S[0] - 'A')][S[0] - 'A'] = 1 ;
    rrep(i,1,n) rep(bit,1<<10){
        int now_ = (S[i] - 'A') ;
        if(bit == 0) (dp[i][1 << now_][now_] += 1) %= mod ;
        rep(j,10){
            (dp[i][bit][j] += dp[i-1][bit][j]) %= mod ;
            if(bit >> now_ & 1 && now_ == j) (dp[i][bit][now_] += dp[i-1][bit][j]) %= mod ;
            else if(!(bit >> now_ & 1)) (dp[i][bit | 1 << now_][now_] += dp[i-1][bit][j]) %= mod ;
        }
    }
    
    ll res = 0 ;
    rrep(bit,1,1<<10) rep(j,10) (res += dp[n-1][bit][j]) %= mod ;
    cout << res << endl ;
}