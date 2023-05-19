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

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    ll res = 0 ;
    for(int i = 0 ; i < (1 << (n - 1)) ; i++){
        ll tmp = 0 , val = 0 ;
        for(int j = 0 ; j < n ; j++){
            val *= 10 ;
            val += (S[j] - '0') ;
            if(i >> j & 1) {
                tmp += val ;
                val = 0 ;
            }
        }
        tmp += val ;
        res += tmp ;
    }
    cout << res << endl ;
}