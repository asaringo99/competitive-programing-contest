#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
int A[550][550] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    vector<TP> vec ;
    rep(i,H-1) rep(j,W){
        if(A[i][j] % 2 != 0){
            vec.push_back({i+1,j+1,i+2,j+1}) ;
            A[i+1][j]++ ;
        }
    }
    rep(i,W-1) if(A[H-1][i] % 2 != 0){
        vec.push_back({H,i+1,H,i+2}) ;
        A[H-1][i+1]++ ;
    }
    cout << vec.size() << endl ;
    rep(i,vec.size()){
        int a , b , c , d ;
        tie(a,b,c,d) = vec[i] ;
        cout << a << " " << b << " " << c << " " << d << endl ;
    }
}