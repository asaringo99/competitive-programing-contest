#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
int S[1007][1007] ;
int res[100007] ;

int main(){
    memset(S,0,sizeof(S)) ;
    cin >> n ;
    rep(i,n){
        int lx , ly , rx , ry ;
        cin >> lx >> ly >> rx >> ry ;
        for(int j = ly ; j < ry ; j++){
            S[lx][j]++ ;
            S[rx][j]-- ;
        }
    }
    for(int i = 0 ; i < 1001 ; i++){
        int sum = 0 ;
        for(int j = 0 ; j < 1001 ; j++){
            sum += S[j][i] ;
            res[sum]++ ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout << res[i] << endl ;
    }
}