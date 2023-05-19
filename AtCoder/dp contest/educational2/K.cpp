#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
int A[110] , dp[101010] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    dp[n] = 0 ;
    for(int i = k ; i >= 0 ; i--){
        int val = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(i + A[j] > k) continue ;
            if(dp[i+A[j]] == 0) val = 1 ;
        }
        dp[i] = val ;
    }
    if(dp[0] == 0) cout << "Second" << endl ;
    else cout << "First" << endl ;
}