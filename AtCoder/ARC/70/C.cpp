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

int x ;

int main(){
    cin >> x ;
    ll sum = 0 ;
    int t = 0 ;
    while(sum < x){
        t++ ;
        sum = t * (t + 1) / 2 ;
    }
    cout << t << endl ;
}