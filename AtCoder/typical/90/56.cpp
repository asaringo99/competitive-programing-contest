#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , S ;
char dp[105][100007] ;
P memo[105][100007] ;
int A[105] , B[105] ;

int main(){
    cin >> n >> S ;
    rep(i,n) cin >> A[i] >> B[i] ;
    rep(i,n+1) rep(j,100007){
        dp[i][j] = '#' ;
        memo[i][j] = P(-1,-1) ;
    }
    dp[1][A[0]] = 'A' ;
    dp[1][B[0]] = 'B' ;
    memo[1][A[0]] = P(0,0) ;
    memo[1][B[0]] = P(0,0) ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j <= S ; j++){
            if(dp[i][j] == 'A' || dp[i][j] == 'B'){
                if(j + A[i] <= S){
                    dp[i+1][j+A[i]] = 'A' ;
                    memo[i+1][j+A[i]] = P(i,j) ;
                }
                if(j + B[i] <= S){
                    dp[i+1][j+B[i]] = 'B' ;
                    memo[i+1][j+B[i]] = P(i,j) ;
                }
            }
        }
    }
    if(dp[n][S] != 'A' && dp[n][S] != 'B'){
        cout << "Impossible" << endl ;
        return 0 ;
    }
    string res = "" ;
    int i = n , j = S ;
    while(memo[i][j] != P(-1,-1)){
        res += dp[i][j] ;
        int p = memo[i][j].first ;
        int q = memo[i][j].second ;
        i = p ;
        j = q ;
    }
    for(int i = 0 ; i < res.size() ; i++) cout << res[res.size() - 1 - i] ;
    cout << endl ;
}