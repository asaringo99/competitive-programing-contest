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

ll n , x ;

int main(){
    cin >> n >> x ;
    ll A[n+1] ;
    A[0] = 0 ;
    for(int i = 1 ; i < n + 1 ; i++) cin >> A[i] ;
    ll count = 0 ;
    for(int i = 1 ; i < n + 1 ; i++){
        if(A[i] + A[i-1] > x){
            ll newx = x - A[i-1] ;
            count +=  A[i] - newx ;
            A[i] = newx ;
        }
    }
    cout << count << endl ;
}