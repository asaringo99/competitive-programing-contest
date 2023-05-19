#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
int A[110][110] , B[110][110] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) cin >> B[i][j] ;
    ll res = 0 ;
    rep(i,H-1) rep(j,W-1){
        if(A[i][j] != B[i][j]){
            ll val = B[i][j] - A[i][j] ;
            A[i][j] += val ;
            A[i+1][j] += val ;
            A[i][j+1] += val ;
            A[i+1][j+1] += val ;
            res += abs(val) ;
        }
    }
    bool ok = true ;
    rep(i,H) rep(j,W) if(A[i][j] != B[i][j]) ok = false ;
    if(ok){
        cout << "Yes" << endl ;
        cout << res << endl ;
    }
    else cout << "No" << endl ;
}