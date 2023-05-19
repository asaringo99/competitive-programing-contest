#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
bool A[30][30] ;
ll dp[(1 << 21) + 10] ;

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    dp[0] = 1 ;
    rep(i,n){
        
    }
}