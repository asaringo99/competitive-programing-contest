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

int T ;

int main(){
    cin >> T ;
    for(int i = 0 ; i < T ; i++){
        ll N ;
        cin >> N ;
        int count = 0 ;
        while(N % 2 == 0){
            count++ ;
            N /= 2 ;
        }
        if(count == 0) cout << "Odd" << endl ;
        else if(count == 1) cout << "Same" << endl ;
        else cout << "Even" << endl ;
    }
}