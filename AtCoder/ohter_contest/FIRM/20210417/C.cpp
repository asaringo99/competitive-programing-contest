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

int a , b ;

int main(){
    cin >> a >> b ;
    set<int> gcd ;
    int res = 0 ;
    for(int i = a ; i <= b ; i++){
        for(int j = 1 ; j * j <= i ; j++){
            if(i % j == 0){
                if(gcd.count(j) == 1) res = max(j,res) ;
                if(gcd.count(i/j) == 1) res = max(i/j,res) ;
                gcd.insert(j) ;
                gcd.insert(i/j) ;
            }
        }
    }
    cout << res << endl ;
}