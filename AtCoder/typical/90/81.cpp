#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;

int A[5050][5050] , S[5050][5050] ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        A[a][b]++ ;
    }
    rep(i,5010) rep(j,5010){
        S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + A[i+1][j+1] ;
    }
    int res = 0 ;
    rrep(i,k+1,5001) rrep(j,k+1,5001){
        res = max(res,S[i][j] - S[i-k-1][j] - S[i][j-k-1] + S[i-k-1][j-k-1]) ;
    }
    cout << res << endl ;
}