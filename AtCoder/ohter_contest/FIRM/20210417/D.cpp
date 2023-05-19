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

int n , p ;

const int MOD = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res = (res * x) % MOD ;
        x = (x * x) % MOD ;
        n >>= 1 ;
    }
    return res % MOD ;
}

int main(){
    cin >> n >> p ;
    cout << powmod(p - 2 , n - 1) * (p - 1) % MOD << endl ;
}