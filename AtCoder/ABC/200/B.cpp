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

ll n , k ;

int main(){
    cin >> n >> k ;
    for(int i = 0 ; i < k ; i++){
        if(n % 200 == 0){
            n /= 200 ;
        }
        else{
            n *= 1000 ;
            n += 200 ;
        }
    }
    cout << n << endl ;
}