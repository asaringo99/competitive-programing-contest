#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , k ;
bool dp[100007] , used[100007] ;
int A[105] ;

int main(){
    cin >> n >> k ;
    memset(dp,0,sizeof(dp)) ;
    rep(i,n) cin >> A[i] ;
    for(int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i - A[j] >= 0 && dp[i - A[j]] == 0) dp[i] = 1 ;
        }
    }
    if(dp[k]) cout << "First" << endl ;
    else cout << "Second" << endl ;
}