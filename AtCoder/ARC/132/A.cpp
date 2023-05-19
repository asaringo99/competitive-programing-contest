#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , q ;
int R[101010] , C[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> R[i] ;
    rep(i,n) cin >> C[i] ;
    cin >> q ;
    rep(i,q){
        int r , c ;
        cin >> r >> c ;
        r-- ; c-- ;
        if(R[r]+C[c] > n) cout << "#" ;
        else cout << "." ;
    }
    cout << endl ;
}