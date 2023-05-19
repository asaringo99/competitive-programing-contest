#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

ll A[50] , B[50] , C[50] ;


int main(){
    memset(A,0,sizeof(A)) ;
    memset(B,0,sizeof(B)) ;
    memset(C,0,sizeof(C)) ;
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A[a%46]++ ;
    }
    rep(i,n){
        ll b ;
        cin >> b ;
        B[b%46]++ ;
    }
    rep(i,n){
        ll c ;
        cin >> c ;
        C[c%46]++ ;
    }
    ll res = 0 ;
    rep(i,46) rep(j,46){
        int k = (46 - (i + j) % 46 + 46) % 46 ;
        res += A[i] * B[j] * C[k] ;
    }
    cout << res << endl ;
}