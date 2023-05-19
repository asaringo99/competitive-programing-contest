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

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res = (res * x) % mod ;
        x = (x * x) % mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n ;
    int A[n] ;
    map<int,int> rem ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        rem[a]++ ;
    }
    int lim = n % 2 == 0 ? 1 : 0 ;
    for(int i = n - 1 ; i >= lim ; i -= 2){
        if(i == 0){
            if(rem[i] != 1){
                cout << 0 << endl ;
                return 0 ;
            }
            break ;
        }
        if(rem[i] != 2) {
            cout << 0 << endl ;
            return 0 ;
        }
    }
    cout << powmod(2,n/2) << endl ;
}