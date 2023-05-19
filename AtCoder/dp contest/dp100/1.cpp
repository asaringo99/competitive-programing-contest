#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 10000 ;

int n , k ;
int pasta[110] ;
ll dp[110][3][2] ;

int main(){
    cin >> n >> k ;
    memset(pasta,0,sizeof(pasta)) ;
    rep(i,k){
        int a, b ;
        cin >> a >> b ;
        a-- ;
        pasta[a] = b ;
    }
    memset(dp,0,sizeof(dp)) ;
    rep(i,n){
        if(i == 0){
            if(pasta[i] == 0) rep(j,3) dp[i+1][j][0] = 1 ;
            else dp[i+1][pasta[i]-1][0] = 1 ;
        }
        else{
            if(pasta[i] == 0){
                rep(j,3) rep(k,3){
                    if(j == k) (dp[i+1][j][1] += dp[i][j][0]) %= mod ;
                    else (dp[i+1][j][0] += dp[i][k][0] + dp[i][k][1]) %= mod ;
                }
            }
            else{
                rep(j,3){
                    if(j == pasta[i]-1) (dp[i+1][pasta[i]-1][1] += dp[i][pasta[i]-1][0]) %= mod ;
                    else{
                        (dp[i+1][pasta[i]-1][0] += dp[i][j][0] + dp[i][j][1]) %= mod ;
                    }
                }
            }
        }
    }
    ll res = 0 ;
    rep(i,3) rep(j,2) (res += dp[n][i][j]) %= mod ;
    cout << res << endl ;
}