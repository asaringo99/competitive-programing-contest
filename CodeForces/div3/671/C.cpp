#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(z,t){
        int n , x , sum = 0 ;
        int A[1010] ;
        memset(A,0,sizeof(A));
        cin >> n >> x ;
        rep(i,n) {
            cin >> A[i] ;
            sum += A[i] ;
        }
        bool ok = true ;
        rep(i,n) if(A[i] != x) ok = false ;
        if(ok){
            cout << 0 << endl ;
            continue ;
        }
        bool gd = false ;
        rep(i,n) if(A[i] == x) gd = true ;
        if(gd){
            cout << 1 << endl ;
            continue ;
        }
        if(x * n == sum){
            cout << 1 << endl ;
            continue ;
        }
        cout << 2 << endl ;
    }
}