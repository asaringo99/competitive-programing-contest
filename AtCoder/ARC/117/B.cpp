#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;
const int mod = 1000000007 ;

int main(){
    cin >> n ;
    ll X[n+1] ;
    X[0] = 0 ;
    for(int i = 1 ; i <= n ; i++) cin >> X[i + 1] ;
    sort(X,X+n+1) ;
    ll res = 1 ;
    for(int i = 0 ; i < n ; i++) res = (res * (X[i+1] - X[i] + 1)) % mod ;
    cout << res << endl ;
}