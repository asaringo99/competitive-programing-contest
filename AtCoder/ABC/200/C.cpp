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
    int A[n] ;
    map<ll,ll> rem ;
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        sum += rem[A[i] % 200] ;
        rem[A[i] % 200]++ ;
    }
    cout << sum << endl ;
}