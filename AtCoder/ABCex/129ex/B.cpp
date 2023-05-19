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

int n ;

int main(){
    cin >> n ;
    int W[n] ;
    for(int i = 0 ; i < n ; i++) cin >> W[i] ;
    int res = INT_MAX ;
    for(int T = 0 ; T < 100 ; T++){
        int sum = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(j <= T) sum += W[j] ;
            else sum -= W[j] ;
        }
        res = min(res,abs(sum)) ;
    }
    cout << res << endl ;
}