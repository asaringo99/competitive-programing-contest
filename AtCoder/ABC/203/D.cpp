#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , k ;
int A[807][807] , B[807][807] ;

bool cal(ll m){
    rep(i,n) rep(j,n) {
        if(A[i][j] > m) B[i][j] = 1 ;
        else B[i][j] = -1 ;
    }
    int S[n+1][n+1] ;
    memset(S,0,sizeof(S)) ;
    rep(i,n) rep(j,n){
        S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + B[i][j] ;
    }
    bool ok = false ;
    rep(i,n) rep(j,n){
        if(i + k > n) break ;
        if(j + k > n) break ;
        if(S[i+k][j+k] - S[i+k][j] - S[i][j+k] + S[i][j] <= 0) ok = true ;
    }
    return ok ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    ll lef = 0 , rig = 1000000007 ;
    while(rig - lef > 0){
        ll m = (rig + lef) / 2 ;
        if(cal(m)){
            rig = m ;
        }
        else lef = m + 1 ;
    }
    cout << rig << endl ;
}