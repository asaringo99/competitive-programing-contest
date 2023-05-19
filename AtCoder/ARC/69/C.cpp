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

ll n , m ;

int main(){
    cin >> n >> m ;
    if(2 * n <= m){
        cout << n + (m - 2 * n) / 4 << endl ;
    }
    else{
        cout << m / 2 << endl ;
    }
}