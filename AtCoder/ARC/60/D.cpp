#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n , s ;

ll f(ll b , ll n){
    ll quotient = 0 ;
    while(n >= b){
        quotient += (n % b) ;
        n /= b ;
    }
    quotient += n ;
    return quotient ;
}

int main(){
    cin >> n >> s ;
    ll lef = 0 , rig = 1e11 ;
    while(rig - lef > 0){
        ll m = (lef + rig) / 2 ;
        if(f(m,n) == s){
            
        }
    }
}