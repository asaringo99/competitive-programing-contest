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

ll a , b , c , d ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b , a % b) ;
}

ll lcm(ll a , ll b) {
    return a * b / gcd(a,b) ;
}

int main(){
    cin >> a >> b >> c >> d ;
    cout << (b - a + 1) - ( b / d + b / c - b / lcm(c,d) ) + ( (a - 1) / d + (a - 1) / c - (a - 1) / lcm(c,d) ) << endl ;
}