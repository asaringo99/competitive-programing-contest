#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n ;

int main(){
    cin >> n ;
    bool ok = false ;
    ll i = 0 , j = 0 ;
    for(;;){
        ll res = n - pow(3,i) ;
        if(res < 0) break ;
        while(res >= 0){
            if(res == 0) {
                ok = true ;
                break ;
            }
            res -= pow(5,j) ;
            j++ ;
        }
        i++ ;
    }
    if(ok) cout << i << " " << j << endl ;
    else cout << -1 << endl ;
}