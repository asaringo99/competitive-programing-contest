#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int A[15][15] ;
map<pair<int,int>,bool> rem ;

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    cin >> m ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        rem[pair<int,int>(x,y)] = true ;
        rem[pair<int,int>(y,x)] = true ;
    }
    int X[n] ; 
    rep(i,n) X[i] = i ;
    int res = INT_MAX ;
    do{
        bool ok = true ;
        int sum = A[X[0]][0] ;
        for(int i = 1 ; i < n ; i++){
            if(rem[pair<int,int>(X[i-1],X[i])]) ok = false ;
            sum += A[X[i]][i] ;
        }
        if(ok) res = min(res,sum) ;
    } while (next_permutation(X,X+n));
    res = res == INT_MAX ? -1 : res ;
    cout << res << endl ;
}