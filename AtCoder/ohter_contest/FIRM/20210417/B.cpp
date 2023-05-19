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

int n , m ;

int main(){
    cin >> n >> m ;
    set<int> S ;
    for(int i = 0 ; i < n ; i++){
        int a ; 
        cin >> a ;
        S.insert(a) ;
    }
    for(int i = 0 ; i < m ; i++){
        int b ;
        cin >> b ;
        if(S.count(b) == 1) S.erase(b) ;
        else S.insert(b) ;
    }
    for(int u : S) cout << u << " " ;
    cout << endl ;
}