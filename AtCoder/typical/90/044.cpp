#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
ll A[200007] ;

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i] ;
    int num = 0 ;
    rep(i,q){
        int t , x , y ;
        cin >> t >> x >> y ;
        x-- ; 
        y-- ;
        if(t == 1) swap(A[(x-num+n) % n],A[(y-num+n) % n]) ;
        if(t == 2) num++ ;
        if(t == 3) cout << A[(x-num+n) % n] << endl ;
    }
}