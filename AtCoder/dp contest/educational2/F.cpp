#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S , T ;
int dp[3030][3030] ;

int main(){
    cin >> S >> T ;
    int s = S.size() , t = T.size() ;
    rrep(i,1,s+1) rrep(j,1,t+1){
        if(S[i-1] == T[j-1]) dp[i][j] = dp[i-1][j-1] + 1 ;
        dp[i][j] = max(dp[i][j],dp[i-1][j]) ;
        dp[i][j] = max(dp[i][j],dp[i][j-1]) ;
    }
    string V = "" ;
    int val = dp[s][t] ;
    for(int i = s ; i >= 1 ; i--){
        for(int j = t ; j >= 1 ; j--){
            if(S[i-1] == T[j-1] && dp[i][j] == val) {
                V += S[i-1] ;
                t = j - 1 ;
                val-- ;
                break ;
            }
        }
    }
    reverse(V.begin(),V.end()) ;
    cout << V << endl ;
}