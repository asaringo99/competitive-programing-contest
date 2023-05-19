#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string s , t ;

int main(){
    cin >> s >> t ;
    int S = s.size() , T = t.size() ;
    int dp[S + 1][T + 1] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 1 ; i < S + 1 ; i++){
        for(int j = 1 ; j < T + 1 ; j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]) ;
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1 ;
            }
        }
    }
    
    int val = dp[S][T] ;
    vector<char> res ;
    for(int i = S ; i > 0 ; i--){
        for(int j = T ; j > 0 ; j--){
            if(dp[i-1][j-1] == dp[i][j] - 1 && val == dp[i][j] && s[i-1] == t[j-1]){
                T = j - 1 ;
                res.push_back(s[i-1]) ;
                val = dp[i-1][j-1] ;
                break ;
            }
        }
    }
    reverse(res.begin(),res.end()) ;
    for(char u : res) cout << u ;
    cout << endl ;
}